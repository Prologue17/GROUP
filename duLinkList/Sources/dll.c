#include<stdio.h>
#include<stdlib.h>
#include"duLinkedList.h"

Status InitList_DuL(DuLinkedList *L){
	//申请内存 
	*L = (DuLinkedList)malloc(sizeof(DuLNode));
	//失败 
	if(!(*L))
		return ERROR;
	//初始化节点 
	(*L)->data = 0;
	(*L)->next = NULL;
	(*L)->prior = NULL;
	return SUCCESS;
}

void DestroyList_DuL(DuLinkedList *L){
	DuLNode *p = (*L)->next;
	DuLNode *pi = (*L);
	//迭代释放内存 
	while(p){
		pi = p;
		p = p->next;
		free(pi);
	}
	//重新设置首元结点 
	(*L)->next = NULL;
	(*L)->prior = NULL;
}

Status InsertAfterList_DuL(DuLNode *p, DuLNode *q){
	//只有首元结点时 
	if(p->next == NULL){
		p->next = q;
		q->next = NULL;
		q->prior = p;
		return SUCCESS;	 
	}
	//对已存在数据节点进行操作 
	q->next = p->next;
	p->next = q;
	q->next->prior = q;
	q->prior = p;
	return SUCCESS;
}

Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q){
	//对只有首元节点进行操作 
	if(p->prior==NULL&&p->next==NULL){
		q->prior = p;
		q->next =NULL;
		p->next = q;
		return SUCCESS;
	}
	/*q->prior = p->prior;
	q->next = q->prior->next;
	q->next->prior = q;
	q->prior->next = q;*/
	//对已存在数据节点进行操作 
	q->prior = p->prior;
	p->prior->next = q;
	q->next = p;
	p->prior = q;
	return SUCCESS;
}

Status DeleteList_DuL(DuLNode *p, ElemType *e){
	DuLNode *del = p->next;
	//只有首元结点结束函数 
	if(del==NULL){
		printf("node error\n");
		return ERROR;
	} 
	//指向被删除节点的下一个节点 
	p->next = del->next;
	//被删除节点不是最后一个节点是进行链接 
	if(del->next!=NULL){
		p->next->prior = p;
	}
	//指针传回被删除节点的数据 
	*e = del->data;
	//释放内存 
	free(del);
	return SUCCESS;
}

void Spray(ElemType e){
	//输出数据 
	printf("%d\n",e);
}

void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e)){
	DuLNode *p = L->next;
	int i = 1;
	while(p){
		//输出序号 
		printf("%d.",i);
		//调用函数 
		(*visit)(p->data);
		p = p->next;
		i++;
	}
}

void PTraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e)){
	DuLNode *p = L->next;
	//指向最后一个节点 
	while(p->next){
		p = p->next;
	}
	//一直前移动节点输出数据 
	while(p){
		(*visit)(p->data);
		p = p->prior;
	}
}

DuLNode* FindNode(DuLinkedList L,int o){
	DuLNode *p = L->next;
	int i = 1;
	//记录有多少个数据节点 
	while(p){
		i++;
		p = p->next;
	}
	//判断输入序号是否合法 
	if(o<1||o>i) {
		printf("序号错误\n");
		return NULL;
	}
	p = L->next;
	int j = 1;
	//返回所查找的节点 
	while(j!=o){
		j++;
		p = p->next;
	}
	//对只有首元节点的特殊化处理 
	if(o == 1&&L->next==NULL) return L;
	return p;
}


