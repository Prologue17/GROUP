#include<stdio.h>
#include<stdlib.h>
#include"duLinkedList.h"

Status InitList_DuL(DuLinkedList *L){
	//�����ڴ� 
	*L = (DuLinkedList)malloc(sizeof(DuLNode));
	//ʧ�� 
	if(!(*L))
		return ERROR;
	//��ʼ���ڵ� 
	(*L)->data = 0;
	(*L)->next = NULL;
	(*L)->prior = NULL;
	return SUCCESS;
}

void DestroyList_DuL(DuLinkedList *L){
	DuLNode *p = (*L)->next;
	DuLNode *pi = (*L);
	//�����ͷ��ڴ� 
	while(p){
		pi = p;
		p = p->next;
		free(pi);
	}
	//����������Ԫ��� 
	(*L)->next = NULL;
	(*L)->prior = NULL;
}

Status InsertAfterList_DuL(DuLNode *p, DuLNode *q){
	//ֻ����Ԫ���ʱ 
	if(p->next == NULL){
		p->next = q;
		q->next = NULL;
		q->prior = p;
		return SUCCESS;	 
	}
	//���Ѵ������ݽڵ���в��� 
	q->next = p->next;
	p->next = q;
	q->next->prior = q;
	q->prior = p;
	return SUCCESS;
}

Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q){
	//��ֻ����Ԫ�ڵ���в��� 
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
	//���Ѵ������ݽڵ���в��� 
	q->prior = p->prior;
	p->prior->next = q;
	q->next = p;
	p->prior = q;
	return SUCCESS;
}

Status DeleteList_DuL(DuLNode *p, ElemType *e){
	DuLNode *del = p->next;
	//ֻ����Ԫ���������� 
	if(del==NULL){
		printf("node error\n");
		return ERROR;
	} 
	//ָ��ɾ���ڵ����һ���ڵ� 
	p->next = del->next;
	//��ɾ���ڵ㲻�����һ���ڵ��ǽ������� 
	if(del->next!=NULL){
		p->next->prior = p;
	}
	//ָ�봫�ر�ɾ���ڵ������ 
	*e = del->data;
	//�ͷ��ڴ� 
	free(del);
	return SUCCESS;
}

void Spray(ElemType e){
	//������� 
	printf("%d\n",e);
}

void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e)){
	DuLNode *p = L->next;
	int i = 1;
	while(p){
		//������ 
		printf("%d.",i);
		//���ú��� 
		(*visit)(p->data);
		p = p->next;
		i++;
	}
}

void PTraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e)){
	DuLNode *p = L->next;
	//ָ�����һ���ڵ� 
	while(p->next){
		p = p->next;
	}
	//һֱǰ�ƶ��ڵ�������� 
	while(p){
		(*visit)(p->data);
		p = p->prior;
	}
}

DuLNode* FindNode(DuLinkedList L,int o){
	DuLNode *p = L->next;
	int i = 1;
	//��¼�ж��ٸ����ݽڵ� 
	while(p){
		i++;
		p = p->next;
	}
	//�ж���������Ƿ�Ϸ� 
	if(o<1||o>i) {
		printf("��Ŵ���\n");
		return NULL;
	}
	p = L->next;
	int j = 1;
	//���������ҵĽڵ� 
	while(j!=o){
		j++;
		p = p->next;
	}
	//��ֻ����Ԫ�ڵ�����⻯���� 
	if(o == 1&&L->next==NULL) return L;
	return p;
}


