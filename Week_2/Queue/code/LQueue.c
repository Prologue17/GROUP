#include<stdio.h>
#include<stdlib.h>
#include "LQueue.h" 

/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void InitLQueue(LQueue *Q){
	//创建头结点 
	Q->front = (Node*)malloc(sizeof(Node));	
	//初始化 
	Q->rear = Q->front;
	Q->front->next = NULL;
	Q->length = 0;
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue *Q){
	Node *p=Q->front;
	//清除所有节点 
	while(p){
		p = Q->front;
		Q->front = Q->front->next;
		free(p);
	}
	//初始化 
	free(Q->front); 
	Q->front = NULL;
	Q->rear = NULL;
	Q->length = 0;
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q){
	if(Q->front == NULL){
		printf("无队\n");
		return ERROR;
	}
	if(Q->front->next == NULL){
		printf("空队\n");
		return ERROR;
	}
	return SUCCESS;
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q e 队列指针Q,返回数据指针e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadLQueue(LQueue *Q, void **e){
	//返回元素 
	(*e) = Q->front->next->data;
	return SUCCESS;
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q){
	//返回长度 
	return Q->length;
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否为空
 */
Status EnLQueue(LQueue *Q, void *data){
	Node *p;
	//申请节点 
	p = (Node*)malloc(sizeof(Node));
	p->data = data;
	//尾插法 
	p->next = NULL;
	Q->rear->next = p;
	Q->rear = p;
	//记录当前节点类型 
	datatype[Q->length] = type;
	//队列长度自增 
	Q->length++;
	return SUCCESS;
}
/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q){
	Node *p;
	//首节点出队 
	p = Q->front->next;
	Q->front->next = p->next;
	//单节点情况 
	if(Q->rear == p)
		Q->rear = Q->front;
	printf("被弹出的队列元素是 ");
	//按照元素类型输出 
	LPrint(p->data, 0); 
	int i = 0;
	//出队后元素类型索引前移 
	for(i = 0; i < Q->length; i++){
		datatype[i] = datatype[i+1];
	}
	//多出的位置置为0 
	datatype[Q->length-1] = '\0';
	free(p);
	Q->length--;
	return SUCCESS; 
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q){
	Node *p;
	//清除除了首届点的节点 
	p = Q->front->next;
	Q->front->next = NULL;
	while(p){
		p = Q->front;
		Q->front = Q->front->next;
		free(p);
	}
	Q->rear = Q->front;
	Q->length = 0;
}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q,int i)){
	Node *p = Q->front->next;
	int i = 0;
	while(p){
		//根据元素类型索引输出 
		(*foo)(p->data,i);
		p = p->next;
		i++;
	} 
}

/**
 *  @name        : void LPrint(void *q)
 *    @description : 操作函数
 *    @param         q 指针q
 
 *  @notice      : None
 */
void LPrint(void *q,int i){
	//按照元素类型输出 
	if(datatype[i] == 'i')
		printf("%d \n", *((int*)q));
	if(datatype[i] == 'c' )
		printf("%c \n", *((char*)q));
	if(datatype[i] == 'f')
		printf("%f \n", *((float*)q));
}

/**************************************************************
 *    End-Multi-Include-Prevent Section
 **************************************************************/
//#endif // LQUEUE_H_INCLUDED


