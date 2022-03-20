#include<stdio.h>
#include<stdlib.h>
#include"linkedList.h"

/*typedef struct Lnode {
	ElemType data;
  	struct LNode *next;
} Lnode, *LinkedList;

typedef enum Status {
	ERROR,
	SUCCESS
} Status;*/

Status InitList(LinkedList *L){
	//以二级指针指向的指针申请内存 
	(*L)=(LinkedList)malloc(sizeof(Lnode));
	//创建失败	
	if(!L)
		return ERROR;
	//创建成功后对首元节点初始化 
	(*L)->data = 0;
	(*L)->next = NULL;
	return SUCCESS;
}


void DestroyList(LinkedList *L){
	//指向第一个存储数据的节点 
	Lnode *p = (*L)->next;
	Lnode *q = NULL;
	//使首元节点孤立存在 
	(*L)->next = NULL;
	//双指针记录下一个节点地址的同时释放节点 
	while(p){
		q = p;
		p = p->next;
		free(q);
	}
}


Status InsertList(Lnode *p, Lnode *q){
	//让插入节点的指针域指向被插入节点的下一位 
	//下一位为 NULL 时指向 NULL 
	q->next = p->next;
	//让被插入节点指向插入节点 
	p->next = q;
	return SUCCESS;
}


Status DeleteList(Lnode *p, ElemType *e){
	//指向第一个存储数据的节点
	Lnode *q = p->next;
	//无数据节点则返回 
	if(!q) return ERROR;
	//让被删除节点前一项指向被删除后一项 
	p->next = q->next;
	//通过指针传递被删除节点的数据 
	*e = q->data;
	//释放将被删除节点 
	free(q);
	return SUCCESS;
}


//输出函数 
void Spray(ElemType e){
	//输出数据域中的数据 
	printf("%d\n",e);
}


void TraverseList(LinkedList L, void (*visit)(ElemType e)){
	//传参将一个函数传入
	//指向第一个存储数据的节点 
	Lnode *p = L->next;
	//计数变量 i 
	int i = 1;
	while(p){
		//输出当前节点的序号 
		printf("%d.",i);
		//调用函数输出数据 
		(*visit)(p->data);
		//指向下一个节点 
		p = p->next;
		//计数自增 
		i++;
	}
}


Status SearchList(LinkedList L, ElemType e){
	//指向第一个存储数据的节点
	Lnode *p = L->next;
	//计数变量 i 
	int i = 1;
	while(p){
		//进行节点数据与传入数据的比较 
		if(p->data==e) {
			//成功则输出节点对应的序号 
			printf("the index of e node is %d\n",i);
			//成功后结束函数返回成功 
			return SUCCESS;
		}
		//指向下一个节点 
		p = p->next;
		//计数变量自增 
		i++;
	}
	//循环结束比较不成功 
	printf("NONE\n");
	//失败结束函数返回失败 
	return ERROR;
}

Status ReverseList(LinkedList *L){
	/*通过三个指针指向三个节点实现节点之间的
	交换的同时保证链表依旧相连*/
	
	Lnode *p1;
	Lnode *p2;
	Lnode *p3;
	//指向第一个存储数据的节点
	p1 = (*L)->next;
	//只有一个头结点结束函数 
	if(p1==NULL) return SUCCESS;
	//指向第二存储数据的节点 
	p2 = p1->next;
	//只有一个头结点一个数据节点不需要反转
	//结束函数返回 
	if(p2==NULL) return SUCCESS;
	//指向第三个存储数据节点 
	p3 = p2->next;
	//状态变量 cnt 
	int cnt = 0;
	while(p3){
		//三个指针指向链表中的三个节点 
		
		//只执行一次
		//第一次的 p1 会作为尾节点 指针域设为 NULL 
		if(!cnt) p1->next = NULL;
		//让第二个节点指向第一个节点 
		//第二节点指向第一节点
		p2->next = p1;
		// p1 和 p2 同时指向第二哥节点 
		p1 = p2;
		// p2 和 p3 同时指向第三哥节点
		p2 = p3;
		// p3 迭代指向后一个节点 
		p3 = p3->next;
		//三个指针都指向了自己的后一个节点
		//状态变量改变 
		cnt++;
	}
	//只有两个节点的情况 设置为尾节点 
	if(!cnt) p1->next = NULL;
	//将最后一个节点与倒数第二个节点连接 
	p2->next = p1;
	//让首元节点指向新的第一个数据节点 
	(*L)->next = p2;
}

Lnode* FindMidNode(LinkedList *L){
	Lnode *p = (*L);
	Lnode *pi = (*L);
	while(p){
		//快指针走一步 
		p = p->next;
		//快指针为 NULL 返回当前数量 /2 的前一个 
		if(!p)
			return pi; 
		//快指针走一步
		p = p->next;
		//返回中间节点 
		if(!p)
			return pi->next;
		//慢指针走一步
		pi = pi->next;
	} 
	return pi;
}

Status IsLoopList(LinkedList L){
	Lnode *p = L;
	Lnode *pi = L;
	while(p){
		//快指针走一步 
		p = p->next;
		// 为 NULL 不是循环链表 
		if(!p)
			return ERROR;
		//快指针走一步  
		p = p->next;
		// 为 NULL 不是循环链表
		if(!p)
			return ERROR;
		//慢指针走一步	
		pi = pi->next;
		//两指针相遇为循环 
		if(p == pi) 
			return SUCCESS;
	}
	return ERROR;
}

void Split(Lnode *LL,Lnode *L0){
	//指向要分割循环链表的头结点 
	Lnode *p1 = L0;
	//指向要分割循环链表的第一个数据节点 
	Lnode *p = L0->next;
	//指向新的循环链表 
	Lnode *p0 = LL;
	//判断是否回到了头结点 
	while(p != L0){
		//状态变量 flag 
		int flag = 0;
		//判断是不是小写元素 
		if(p->data >= 'a' && p->data <= 'z'){
			//状态变量改变 
			flag = 1;
			//新的循环链表与小写字母节点连接 
			p0->next = p;
			//原链表链接到被分割节点下一个节点 
			p1->next = p->next;
			//被分割节点与新链表形成循环 
			p->next = LL;
			//指向循环链表最后一个节点 
			p0 = p;
			//指向下个节点 
			p = p1->next;
		}
		//不是小写字母正常迭代 
		if(!flag){
			p1 = p;
			p = p->next;
		}
	}
}

Lnode* ReverseEvenList(LinkedList *L){
	Lnode *p1 = (*L);
	Lnode *p0 = (*L);
	Lnode *p2 = (*L);
	Lnode *t = NULL;
	while(p1){
		//指向下一个节点 
		p1 = p1->next;
		//后一位为 NULL 
		if(!p1)
			return *L;
		p1 = p1->next;
		//剩下了一个节点是不用交换 
		if(!p1)
			return *L;
		//同时指向三个节点进行交换 
		p0 = p0->next;
		p0->next = p1->next;
		p1->next = p0;
		p2->next = p1;
		//按照顺序指向三个节点 
		t = p1;
		p1 = p0;
		p0 = t;
		p2 = p1;
		p0 = p1; 
	}
	
}

Lnode* transpose(Lnode *L){
	//传入首元节点的下一个节点 
	
	//传入为空直接返回 
    if(!L) return L;
    //到了最后一节点返回最后一个节点 
    if (L->next == NULL) return L;
    //最后一个节点保存 
    Lnode *last = transpose(L->next);
    // 当 1->2 时 让  1<-2 
    L->next->next = L;
    //链接上的新节点 设为 NULL 
    L->next = NULL;
    return last;
}

Status RlistFstack(Lnode*L){
	/*传入首元结点后第一个数据节点，可以使
	除了首元节点的数据节点进行反转，而不会
	影响到首元结点*/
	
	Lnode *p = L->next;
	Lnode *rear;
	rear = transpose(p);
	L->next = rear;
	return SUCCESS;
}

Lnode* FindNode(LinkedList L,int o){
	Lnode *p = L->next;
	int i = 1;
	//统计数据节点个数 
	while(p){
		i++;
		p = p->next;
	}
	//输入合法判断 
	if(o<1||o>i) {
		//printf("序号错误\n");
		return NULL;
	}
	p = L->next;
	int j = 1;
	//返回对应节点 
	while(j!=o){
		j++;
		p = p->next;
	}
	//对只有首元节点存在的特殊化处理 
	if(o == 1&&L->next==NULL) return L;
	return p;
}

