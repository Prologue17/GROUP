#include<stdio.h>
#include<stdlib.h>
#include "LinkStack.h" 
//链栈

//初始化栈
Status initLStack(LinkStack *s){
	//创建一个头结点 
	s->top = (StackNode*)malloc(sizeof(StackNode));
	if(!s->top)
		return ERROR;
	//初始化头结点 
	s->top->data = 0;
	s->top->next= NULL;
	s->count = 0;
	return SUCCESS;
}

//判断栈是否为空
Status isEmptyLStack(LinkStack *s){
	if(s->top == NULL){
		printf("无栈\n"); 
		return ERROR;
	}
	if(s->count == 0){
		printf("栈空\n");
		return ERROR;
	}
	return SUCCESS;	
}

//得到栈顶元素
Status getTopLStack(LinkStack *s,ElemType *e){
	//返回栈顶元素 
	(*e) = s->top->data;
	return SUCCESS;
}

//清空栈
Status clearLStack(LinkStack *s){
	StackNode *p;
	//清空除了首节点的节点 
	while(s->top->next!=NULL){
			p=s->top;
			s->top=p->next;
			//计数器自减 
			s->count--;
			free(p);
		}
	return SUCCESS;
}

//销毁栈
Status destroyLStack(LinkStack *s){
	StackNode *p;
	//释放除了首节点的节点 
	while(s->top->next!=NULL){
			p=s->top;
			s->top=p->next;
			s->count--;
			free(p);
		}
		//释放首节点 
		free(s->top);
		//初始化 
		s->top = NULL;
	return SUCCESS;
}

//检测栈长度
Status LStackLength(LinkStack *s,int *length){
	//返回长度 
	*length = s->count;
	return SUCCESS;
}

//入栈
Status pushLStack(LinkStack *s,ElemType data){
	StackNode *p;
	//新建节点 
	p = (StackNode*)malloc(sizeof(StackNode));
	p->data = data;
	//新节点指向原栈顶 
	p->next = s->top;
	//栈顶更迭 
	s->top = p;
	s->count++;
	/*p = (StackNode*)malloc(sizeof(StackNode));
	p->data = data;
	p->next = (*s)->top;
	(*s)->top = p;
	(*s)->count++;*/
	return SUCCESS;
}

//出栈
Status popLStack(LinkStack *s,ElemType *data){
	StackNode *p;
	//数据传回 
	(*data) = s->top->data;
	//释放节点 
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
