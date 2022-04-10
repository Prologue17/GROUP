#include<stdio.h>
#include<stdlib.h>
#include"binary_sort_tree.h" 

//����һ���µ��� 
int BST_init(BinarySortTreePtr T){
	T->root = NULL;
	int e = 0;int i = -1;
	printf("������Ҫ�������: \n");
	printf("����С�ڵ���0������ֹͣ����\n");
	fflush(stdin);
	i = scanf("%d",&e);
	//������� 
	if(!i){
		printf("�����������\n");
		T->root = NULL;
		system("PAUSE");
		//����ʧ�� 
		return 0;
	}
	//����С�ڵ��� 0 ����ֹͣ 
	while(e > 0){
		//����ڵ� 
		BST_insert(&T->root, e);
		printf("������Ҫ�������: \n");
		printf("����С�ڵ���0������ֹͣ����\n");
		fflush(stdin);
		i = scanf("%d",&e);
		//������� 
		if(!i){
			printf("�����������\n");
			T->root = NULL;
			system("PAUSE");
			//����ʧ�� 
			return 0;
		}
	}
	//�����ɹ� 
	return 1;
}

int BST_insert(NodePtr *T, ElemType e){
	//λ��Ϊ��  ���Բ��� 
	if(!(*T)){
		//���ɽڵ� 
		Node *s;
		s = (Node*)malloc(sizeof(Node));
		s->value = e;
		s->left = s->right = NULL;
		*T = s;
	}
	//�ȸ��ڵ�С���������� 
	else if(e < (*T)->value){
		BST_insert(&(*T)->left, e);
	}
	//�ȸ��ڵ����������� 
	else if(e > (*T)->value){
		BST_insert(&(*T)->right, e);
	}
	//������ͬ���������в��� 
	else{
		printf("�Ѵ�����ͬ����\n");
		return 0;
	} 
}

int BST_delete(NodePtr *T, ElemType e){
	 Node *p;
	 p = (*T);
	 Node *f = NULL;
	 //Ѱ��Ҫɾ���Ľڵ� 
	 while(p){
	 	//�ҵ� 
	 	if(p->value == e) 
	 		break;
	 	f = p;
	 	//�ȸ��ڵ���Ҳ��� 
	 	if(p->value < e)
	 		p = p->right;
	 	//�ȸ��ڵ�С����� 
		else
			p = p->left;
	 } 
	 //�ҵ�Ϊ�� ��������ָ���ڵ� 
	 if(!p){
	 	printf("û��ָ���Ľڵ�\n");
	 	system("PAUSE");
	 	return 0;
	 }
	 
	 Node *q = p;
	 Node *s = p->left;
	 //�������������� 
	 if(p->left&&p->right){
	 	//Ѱ���������������һ���ڵ� 
	 	//���ȸ��ڵ�С�������Ǹ��ڵ� 
	 	while(s->right){
	 		q = s;
			s = s->right;
		 }
		 //���ȸ��ڵ�С�����ڵ����� ���õ����ڵ�λ�� 
		p->value = s->value;
		//���������ҽڵ� 
		if(q != p)
		//�����ڵ��������������ԭ������ 
			q->right = s->left; 
		//���ҽڵ� 
		else
			q->left = s->left;
		free(s);
		printf("ɾ���ɹ�\n");
		system("PAUSE");
		return 0;
	 }
	 //�������� 
	 else if(!p->right){
	 	//���������� 
	 	p = p->left;
	 }
	 //�������� 
	 else if(!p->left){
	 	//���������� 
	 	p = p->right;
	 }
	 //ɾ���ڵ�Ϊ���ڵ� 
	 if(!f)
	 	(*T) = p;
	//��������������� 
	 else if(q == f->left)
	 	f->left = p;
	 else
	 	f->right = p;
	 free(q);                                                                                                                                                                                                                                 
}

int BST_search(NodePtr T, ElemType e){
	//���ҿ� 
	if(!T) return 0;
	//���ҳɹ� 
	if(e == T->value) 
		return 1;
	//С�� ����� 
	else if(e < T->value)
		BST_search(T->left, e);
	//���� �Ҳ��� 
	else 
		BST_search(T->right, e);
		
}

//������� 
void output(NodePtr T){
	printf("%d", T->value);
}

int BST_preorderR(NodePtr T, void (*visit)(NodePtr)){
	//������ 
	if(T){
		(*visit)(T);
		BST_preorderR(T->left, output);
		BST_preorderR(T->right, output);
	}
}

int BST_inorderR(NodePtr T, void (*visit)(NodePtr)){
	//����� 
	if(T){
		BST_preorderR(T->left, output);
		(*visit)(T);
		BST_preorderR(T->right, output);
	}
}

int BST_postorderR(NodePtr T, void (*visit)(NodePtr)){
	//���Ҹ� 
	if(T){
		BST_preorderR(T->left, output);
		BST_preorderR(T->right, output);
		(*visit)(T);
	}
}

int BST_preorderI(NodePtr T, void (*visit)(NodePtr)){
	Node *p = T;
	Stack *s;
	//���ɳ�ʼ��ջ 
	s = (Stack*)malloc(sizeof(Stack));
	s->base = s->top = 0;
	s->data[s->top] = p;
	s->top++;
	//ջ��Ϊ�� 
	while(s->base != s->top){
		//��ջ���ڵ� 
		p = s->data[s->top-1];
		s->top--;
		(*visit)(p);
		//��ջ���ڵ���������� 
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
	//���ɳ�ʼ��ջ 
	Stack *s;
	s = (Stack*)malloc(sizeof(Stack));
	s->base = s->top = 0;
	//ջ��Ϊ�� ��δ������� 
	while(p||s->base != s->top){
		if(p){
			//��ջ 
			s->data[s->top] = p;
			s->top++;
			//���������� 
			p = p->left;
		}
		//
		else{
			//��ջ 
			q = s->data[s->top-1];
			s->top--;
			(*visit)(q);
			//������ջԪ�ص������� 
			p = q->right;
		}
	}
}

int BST_postorderI(NodePtr T, void (*visit)(NodePtr)){
	Node *p = T;
	//ָ��ջ 
	Stack *s;
	s = (Stack*)malloc(sizeof(Stack));
	s->base = s->top = 0;
	//��Ǳ�����������ջ 
	int flagstack[100];
	int flagtop = -1;
	while(p||flagtop != -1){
		if(p){
			//��ջ 
			s->data[s->top] = p;
			s->top++;
			//��������Ϊ 1
			flagtop++;
			flagstack[flagtop] = 1;
			p = p->left;
		}
		
		else if(flagstack[flagtop] == 1){
			//��ջ��ǰ�ڵ������� 
			p = s->data[s->top-1];
			flagstack[flagtop] = 2;
			//�������ڵ�������� 
			p = p->right;
		}
		//��ǰ�ڵ����������ѱ��� 
		else{
			//��ջ 
			p = s->data[s->top-1];
			s->top--;
			(*visit)(p);
			flagtop--;
			//������ջԪ�� 
			p = NULL; 
		}
	}
}

int BST_levelOrder(NodePtr T, void (*visit)(NodePtr)){
	Node *p;
	Queue *qu;
	//��ʼ������ 
	qu = (Queue*)malloc(sizeof(Queue));
	qu->front = qu->rear = 0;
	qu->data[qu->front] = T;
	qu->rear++;
	//�Ӳ�Ϊ�� 
	while(qu->front != qu->rear){
		//��ջ 
		p = qu->data[qu->front];
		qu->front++;
		(*visit)(p);
		//��ջ����ջ�ڵ�������� 
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














