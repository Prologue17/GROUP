#include<stdio.h>
#include<stdlib.h>
#include"binary_sort_tree.h" 

//生成一颗新的树 
int BST_init(BinarySortTreePtr T){
	T->root = NULL;
	int e = 0;int i = -1;
	printf("请输入要插入的数: \n");
	printf("输入小于等于0的数即停止输入\n");
	fflush(stdin);
	i = scanf("%d",&e);
	//输入错误 
	if(!i){
		printf("数据输入错误\n");
		T->root = NULL;
		system("PAUSE");
		//创建失败 
		return 0;
	}
	//输入小于等于 0 的数停止 
	while(e > 0){
		//插入节点 
		BST_insert(&T->root, e);
		printf("请输入要插入的数: \n");
		printf("输入小于等于0的数即停止输入\n");
		fflush(stdin);
		i = scanf("%d",&e);
		//输入错误 
		if(!i){
			printf("数据输入错误\n");
			T->root = NULL;
			system("PAUSE");
			//创建失败 
			return 0;
		}
	}
	//创建成功 
	return 1;
}

int BST_insert(NodePtr *T, ElemType e){
	//位置为空  可以插入 
	if(!(*T)){
		//生成节点 
		Node *s;
		s = (Node*)malloc(sizeof(Node));
		s->value = e;
		s->left = s->right = NULL;
		*T = s;
	}
	//比根节点小插入左子树 
	else if(e < (*T)->value){
		BST_insert(&(*T)->left, e);
	}
	//比根节点大插入右子树 
	else if(e > (*T)->value){
		BST_insert(&(*T)->right, e);
	}
	//存在相同的数不进行插入 
	else{
		printf("已存在相同的数\n");
		return 0;
	} 
}

int BST_delete(NodePtr *T, ElemType e){
	 Node *p;
	 p = (*T);
	 Node *f = NULL;
	 //寻找要删除的节点 
	 while(p){
	 	//找得 
	 	if(p->value == e) 
	 		break;
	 	f = p;
	 	//比根节点大右查找 
	 	if(p->value < e)
	 		p = p->right;
	 	//比根节点小左查找 
		else
			p = p->left;
	 } 
	 //找得为空 即不存在指定节点 
	 if(!p){
	 	printf("没有指定的节点\n");
	 	system("PAUSE");
	 	return 0;
	 }
	 
	 Node *q = p;
	 Node *s = p->left;
	 //左右子树均存在 
	 if(p->left&&p->right){
	 	//寻找左子树中序最后一个节点 
	 	//即比根节点小的最大的那个节点 
	 	while(s->right){
	 		q = s;
			s = s->right;
		 }
		 //将比根节点小的最大节点数据 放置到根节点位置 
		p->value = s->value;
		//左子树有右节点 
		if(q != p)
		//将最大节点的左子树连接上原来的树 
			q->right = s->left; 
		//无右节点 
		else
			q->left = s->left;
		free(s);
		printf("删除成功\n");
		system("PAUSE");
		return 0;
	 }
	 //无右子树 
	 else if(!p->right){
	 	//接上左子树 
	 	p = p->left;
	 }
	 //无左子树 
	 else if(!p->left){
	 	//接上右子树 
	 	p = p->right;
	 }
	 //删除节点为根节点 
	 if(!f)
	 	(*T) = p;
	//根据上面接上子树 
	 else if(q == f->left)
	 	f->left = p;
	 else
	 	f->right = p;
	 free(q);                                                                                                                                                                                                                                 
}

int BST_search(NodePtr T, ElemType e){
	//查找空 
	if(!T) return 0;
	//查找成功 
	if(e == T->value) 
		return 1;
	//小于 左查找 
	else if(e < T->value)
		BST_search(T->left, e);
	//大于 右查找 
	else 
		BST_search(T->right, e);
		
}

//输出函数 
void output(NodePtr T){
	printf("%d", T->value);
}

int BST_preorderR(NodePtr T, void (*visit)(NodePtr)){
	//根左右 
	if(T){
		(*visit)(T);
		BST_preorderR(T->left, output);
		BST_preorderR(T->right, output);
	}
}

int BST_inorderR(NodePtr T, void (*visit)(NodePtr)){
	//左根右 
	if(T){
		BST_preorderR(T->left, output);
		(*visit)(T);
		BST_preorderR(T->right, output);
	}
}

int BST_postorderR(NodePtr T, void (*visit)(NodePtr)){
	//左右根 
	if(T){
		BST_preorderR(T->left, output);
		BST_preorderR(T->right, output);
		(*visit)(T);
	}
}

int BST_preorderI(NodePtr T, void (*visit)(NodePtr)){
	Node *p = T;
	Stack *s;
	//生成初始化栈 
	s = (Stack*)malloc(sizeof(Stack));
	s->base = s->top = 0;
	s->data[s->top] = p;
	s->top++;
	//栈不为空 
	while(s->base != s->top){
		//出栈根节点 
		p = s->data[s->top-1];
		s->top--;
		(*visit)(p);
		//入栈根节点的左右子树 
		if(p->right){
			s->data[s->top] = p->right;
			s->top++;
		}
		if(p->left){
			s->data[s->top] = p->left;
			s->top++;
		}
	}
} 

int BST_inorderI(NodePtr T, void (*visit)(NodePtr)){
	Node *p = T;
	Node *q = NULL;
	//生成初始化栈 
	Stack *s;
	s = (Stack*)malloc(sizeof(Stack));
	s->base = s->top = 0;
	//栈不为空 且未遍历完成 
	while(p||s->base != s->top){
		if(p){
			//入栈 
			s->data[s->top] = p;
			s->top++;
			//遍历左子树 
			p = p->left;
		}
		//
		else{
			//出栈 
			q = s->data[s->top-1];
			s->top--;
			(*visit)(q);
			//遍历出栈元素的右子数 
			p = q->right;
		}
	}
}

int BST_postorderI(NodePtr T, void (*visit)(NodePtr)){
	Node *p = T;
	//指针栈 
	Stack *s;
	s = (Stack*)malloc(sizeof(Stack));
	s->base = s->top = 0;
	//标记被遍历次数的栈 
	int flagstack[100];
	int flagtop = -1;
	while(p||flagtop != -1){
		if(p){
			//入栈 
			s->data[s->top] = p;
			s->top++;
			//遍历次数为 1
			flagtop++;
			flagstack[flagtop] = 1;
			p = p->left;
		}
		
		else if(flagstack[flagtop] == 1){
			//入栈当前节点右子树 
			p = s->data[s->top-1];
			flagstack[flagtop] = 2;
			//遍历根节点的右子树 
			p = p->right;
		}
		//当前节点左右子树已遍历 
		else{
			//出栈 
			p = s->data[s->top-1];
			s->top--;
			(*visit)(p);
			flagtop--;
			//继续出栈元素 
			p = NULL; 
		}
	}
}

int BST_levelOrder(NodePtr T, void (*visit)(NodePtr)){
	Node *p;
	Queue *qu;
	//初始化队列 
	qu = (Queue*)malloc(sizeof(Queue));
	qu->front = qu->rear = 0;
	qu->data[qu->front] = T;
	qu->rear++;
	//队不为空 
	while(qu->front != qu->rear){
		//出栈 
		p = qu->data[qu->front];
		qu->front++;
		(*visit)(p);
		//入栈被出栈节点的两子树 
		if(p->left){
			qu->data[qu->rear] = p->left;
			qu->rear++;
		}
		if(p->right){
			qu->data[qu->rear] = p->right;
			qu->rear++;
		}
	}
}














