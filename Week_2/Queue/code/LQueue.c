#include<stdio.h>
#include<stdlib.h>
#include "LQueue.h" 

/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : ��ʼ������
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void InitLQueue(LQueue *Q){
	//����ͷ��� 
	Q->front = (Node*)malloc(sizeof(Node));	
	//��ʼ�� 
	Q->rear = Q->front;
	Q->front->next = NULL;
	Q->length = 0;
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : ���ٶ���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue *Q){
	Node *p=Q->front;
	//������нڵ� 
	while(p){
		p = Q->front;
		Q->front = Q->front->next;
		free(p);
	}
	//��ʼ�� 
	free(Q->front); 
	Q->front = NULL;
	Q->rear = NULL;
	Q->length = 0;
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q){
	if(Q->front == NULL){
		printf("�޶�\n");
		return ERROR;
	}
	if(Q->front->next == NULL){
		printf("�ն�\n");
		return ERROR;
	}
	return SUCCESS;
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : �鿴��ͷԪ��
 *    @param         Q e ����ָ��Q,��������ָ��e
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
 */
Status GetHeadLQueue(LQueue *Q, void **e){
	//����Ԫ�� 
	(*e) = Q->front->next->data;
	return SUCCESS;
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : ȷ�����г���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q){
	//���س��� 
	return Q->length;
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : ��Ӳ���
 *    @param         Q ����ָ��Q,�������ָ��data
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ�Ϊ��
 */
Status EnLQueue(LQueue *Q, void *data){
	Node *p;
	//����ڵ� 
	p = (Node*)malloc(sizeof(Node));
	p->data = data;
	//β�巨 
	p->next = NULL;
	Q->rear->next = p;
	Q->rear = p;
	//��¼��ǰ�ڵ����� 
	datatype[Q->length] = type;
	//���г������� 
	Q->length++;
	return SUCCESS;
}
/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q){
	Node *p;
	//�׽ڵ���� 
	p = Q->front->next;
	Q->front->next = p->next;
	//���ڵ���� 
	if(Q->rear == p)
		Q->rear = Q->front;
	printf("�������Ķ���Ԫ���� ");
	//����Ԫ��������� 
	LPrint(p->data, 0); 
	int i = 0;
	//���Ӻ�Ԫ����������ǰ�� 
	for(i = 0; i < Q->length; i++){
		datatype[i] = datatype[i+1];
	}
	//�����λ����Ϊ0 
	datatype[Q->length-1] = '\0';
	free(p);
	Q->length--;
	return SUCCESS; 
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q){
	Node *p;
	//��������׽��Ľڵ� 
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
 *    @description : ������������
 *    @param         Q ����ָ��Q����������ָ��foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q,int i)){
	Node *p = Q->front->next;
	int i = 0;
	while(p){
		//����Ԫ������������� 
		(*foo)(p->data,i);
		p = p->next;
		i++;
	} 
}

/**
 *  @name        : void LPrint(void *q)
 *    @description : ��������
 *    @param         q ָ��q
 
 *  @notice      : None
 */
void LPrint(void *q,int i){
	//����Ԫ��������� 
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


