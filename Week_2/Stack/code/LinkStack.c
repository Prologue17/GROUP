#include<stdio.h>
#include<stdlib.h>
#include "LinkStack.h" 
//��ջ

//��ʼ��ջ
Status initLStack(LinkStack *s){
	//����һ��ͷ��� 
	s->top = (StackNode*)malloc(sizeof(StackNode));
	if(!s->top)
		return ERROR;
	//��ʼ��ͷ��� 
	s->top->data = 0;
	s->top->next= NULL;
	s->count = 0;
	return SUCCESS;
}

//�ж�ջ�Ƿ�Ϊ��
Status isEmptyLStack(LinkStack *s){
	if(s->top == NULL){
		printf("��ջ\n"); 
		return ERROR;
	}
	if(s->count == 0){
		printf("ջ��\n");
		return ERROR;
	}
	return SUCCESS;	
}

//�õ�ջ��Ԫ��
Status getTopLStack(LinkStack *s,ElemType *e){
	//����ջ��Ԫ�� 
	(*e) = s->top->data;
	return SUCCESS;
}

//���ջ
Status clearLStack(LinkStack *s){
	StackNode *p;
	//��ճ����׽ڵ�Ľڵ� 
	while(s->top->next!=NULL){
			p=s->top;
			s->top=p->next;
			//�������Լ� 
			s->count--;
			free(p);
		}
	return SUCCESS;
}

//����ջ
Status destroyLStack(LinkStack *s){
	StackNode *p;
	//�ͷų����׽ڵ�Ľڵ� 
	while(s->top->next!=NULL){
			p=s->top;
			s->top=p->next;
			s->count--;
			free(p);
		}
		//�ͷ��׽ڵ� 
		free(s->top);
		//��ʼ�� 
		s->top = NULL;
	return SUCCESS;
}

//���ջ����
Status LStackLength(LinkStack *s,int *length){
	//���س��� 
	*length = s->count;
	return SUCCESS;
}

//��ջ
Status pushLStack(LinkStack *s,ElemType data){
	StackNode *p;
	//�½��ڵ� 
	p = (StackNode*)malloc(sizeof(StackNode));
	p->data = data;
	//�½ڵ�ָ��ԭջ�� 
	p->next = s->top;
	//ջ������ 
	s->top = p;
	s->count++;
	/*p = (StackNode*)malloc(sizeof(StackNode));
	p->data = data;
	p->next = (*s)->top;
	(*s)->top = p;
	(*s)->count++;*/
	return SUCCESS;
}

//��ջ
Status popLStack(LinkStack *s,ElemType *data){
	StackNode *p;
	//���ݴ��� 
	(*data) = s->top->data;
	//�ͷŽڵ� 
	p = s->top;
	s->top = s->top->next;
	free(p);
	s->count--;
	/*(*data) = (*s)->top->data;
	p = (*s)->top;
	(*s)->top = (*s)->top->next;
	free(p);
	(*s)->count--;*/
	return SUCCESS;
}


//#endif 
