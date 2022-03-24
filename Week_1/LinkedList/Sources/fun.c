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
	//�Զ���ָ��ָ���ָ�������ڴ� 
	(*L)=(LinkedList)malloc(sizeof(Lnode));
	//����ʧ��	
	if(!L)
		return ERROR;
	//�����ɹ������Ԫ�ڵ��ʼ�� 
	(*L)->data = 0;
	(*L)->next = NULL;
	return SUCCESS;
}


void DestroyList(LinkedList *L){
	//ָ���һ���洢���ݵĽڵ� 
	Lnode *p = (*L)->next;
	Lnode *q = NULL;
	//ʹ��Ԫ�ڵ�������� 
	(*L)->next = NULL;
	//˫ָ���¼��һ���ڵ��ַ��ͬʱ�ͷŽڵ� 
	while(p){
		q = p;
		p = p->next;
		free(q);
	}
}


Status InsertList(Lnode *p, Lnode *q){
	//�ò���ڵ��ָ����ָ�򱻲���ڵ����һλ 
	//��һλΪ NULL ʱָ�� NULL 
	q->next = p->next;
	//�ñ�����ڵ�ָ�����ڵ� 
	p->next = q;
	return SUCCESS;
}


Status DeleteList(Lnode *p, ElemType *e){
	//ָ���һ���洢���ݵĽڵ�
	Lnode *q = p->next;
	//�����ݽڵ��򷵻� 
	if(!q) return ERROR;
	//�ñ�ɾ���ڵ�ǰһ��ָ��ɾ����һ�� 
	p->next = q->next;
	//ͨ��ָ�봫�ݱ�ɾ���ڵ������ 
	*e = q->data;
	//�ͷŽ���ɾ���ڵ� 
	free(q);
	return SUCCESS;
}


//������� 
void Spray(ElemType e){
	//����������е����� 
	printf("%d\n",e);
}


void TraverseList(LinkedList L, void (*visit)(ElemType e)){
	//���ν�һ����������
	//ָ���һ���洢���ݵĽڵ� 
	Lnode *p = L->next;
	//�������� i 
	int i = 1;
	while(p){
		//�����ǰ�ڵ����� 
		printf("%d.",i);
		//���ú���������� 
		(*visit)(p->data);
		//ָ����һ���ڵ� 
		p = p->next;
		//�������� 
		i++;
	}
}


Status SearchList(LinkedList L, ElemType e){
	//ָ���һ���洢���ݵĽڵ�
	Lnode *p = L->next;
	//�������� i 
	int i = 1;
	while(p){
		//���нڵ������봫�����ݵıȽ� 
		if(p->data==e) {
			//�ɹ�������ڵ��Ӧ����� 
			printf("the index of e node is %d\n",i);
			//�ɹ�������������سɹ� 
			return SUCCESS;
		}
		//ָ����һ���ڵ� 
		p = p->next;
		//������������ 
		i++;
	}
	//ѭ�������Ƚϲ��ɹ� 
	printf("NONE\n");
	//ʧ�ܽ�����������ʧ�� 
	return ERROR;
}

Status ReverseList(LinkedList *L){
	/*ͨ������ָ��ָ�������ڵ�ʵ�ֽڵ�֮���
	������ͬʱ��֤������������*/
	
	Lnode *p1;
	Lnode *p2;
	Lnode *p3;
	//ָ���һ���洢���ݵĽڵ�
	p1 = (*L)->next;
	//ֻ��һ��ͷ���������� 
	if(p1==NULL) return SUCCESS;
	//ָ��ڶ��洢���ݵĽڵ� 
	p2 = p1->next;
	//ֻ��һ��ͷ���һ�����ݽڵ㲻��Ҫ��ת
	//������������ 
	if(p2==NULL) return SUCCESS;
	//ָ��������洢���ݽڵ� 
	p3 = p2->next;
	//״̬���� cnt 
	int cnt = 0;
	while(p3){
		//����ָ��ָ�������е������ڵ� 
		
		//ִֻ��һ��
		//��һ�ε� p1 ����Ϊβ�ڵ� ָ������Ϊ NULL 
		if(!cnt) p1->next = NULL;
		//�õڶ����ڵ�ָ���һ���ڵ� 
		//�ڶ��ڵ�ָ���һ�ڵ�
		p2->next = p1;
		// p1 �� p2 ͬʱָ��ڶ���ڵ� 
		p1 = p2;
		// p2 �� p3 ͬʱָ�������ڵ�
		p2 = p3;
		// p3 ����ָ���һ���ڵ� 
		p3 = p3->next;
		//����ָ�붼ָ�����Լ��ĺ�һ���ڵ�
		//״̬�����ı� 
		cnt++;
	}
	//ֻ�������ڵ����� ����Ϊβ�ڵ� 
	if(!cnt) p1->next = NULL;
	//�����һ���ڵ��뵹���ڶ����ڵ����� 
	p2->next = p1;
	//����Ԫ�ڵ�ָ���µĵ�һ�����ݽڵ� 
	(*L)->next = p2;
}

Lnode* FindMidNode(LinkedList *L){
	Lnode *p = (*L);
	Lnode *pi = (*L);
	while(p){
		//��ָ����һ�� 
		p = p->next;
		//��ָ��Ϊ NULL ���ص�ǰ���� /2 ��ǰһ�� 
		if(!p)
			return pi; 
		//��ָ����һ��
		p = p->next;
		//�����м�ڵ� 
		if(!p)
			return pi->next;
		//��ָ����һ��
		pi = pi->next;
	} 
	return pi;
}

Status IsLoopList(LinkedList L){
	Lnode *p = L;
	Lnode *pi = L;
	while(p){
		//��ָ����һ�� 
		p = p->next;
		// Ϊ NULL ����ѭ������ 
		if(!p)
			return ERROR;
		//��ָ����һ��  
		p = p->next;
		// Ϊ NULL ����ѭ������
		if(!p)
			return ERROR;
		//��ָ����һ��	
		pi = pi->next;
		//��ָ������Ϊѭ�� 
		if(p == pi) 
			return SUCCESS;
	}
	return ERROR;
}

void Split(Lnode *LL,Lnode *L0){
	//ָ��Ҫ�ָ�ѭ�������ͷ��� 
	Lnode *p1 = L0;
	//ָ��Ҫ�ָ�ѭ������ĵ�һ�����ݽڵ� 
	Lnode *p = L0->next;
	//ָ���µ�ѭ������ 
	Lnode *p0 = LL;
	//�ж��Ƿ�ص���ͷ��� 
	while(p != L0){
		//״̬���� flag 
		int flag = 0;
		//�ж��ǲ���СдԪ�� 
		if(p->data >= 'a' && p->data <= 'z'){
			//״̬�����ı� 
			flag = 1;
			//�µ�ѭ��������Сд��ĸ�ڵ����� 
			p0->next = p;
			//ԭ�������ӵ����ָ�ڵ���һ���ڵ� 
			p1->next = p->next;
			//���ָ�ڵ����������γ�ѭ�� 
			p->next = LL;
			//ָ��ѭ���������һ���ڵ� 
			p0 = p;
			//ָ���¸��ڵ� 
			p = p1->next;
		}
		//����Сд��ĸ�������� 
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
		//ָ����һ���ڵ� 
		p1 = p1->next;
		//��һλΪ NULL 
		if(!p1)
			return *L;
		p1 = p1->next;
		//ʣ����һ���ڵ��ǲ��ý��� 
		if(!p1)
			return *L;
		//ͬʱָ�������ڵ���н��� 
		p0 = p0->next;
		p0->next = p1->next;
		p1->next = p0;
		p2->next = p1;
		//����˳��ָ�������ڵ� 
		t = p1;
		p1 = p0;
		p0 = t;
		p2 = p1;
		p0 = p1; 
	}
	
}

Lnode* transpose(Lnode *L){
	//������Ԫ�ڵ����һ���ڵ� 
	
	//����Ϊ��ֱ�ӷ��� 
    if(!L) return L;
    //�������һ�ڵ㷵�����һ���ڵ� 
    if (L->next == NULL) return L;
    //���һ���ڵ㱣�� 
    Lnode *last = transpose(L->next);
    // �� 1->2 ʱ ��  1<-2 
    L->next->next = L;
    //�����ϵ��½ڵ� ��Ϊ NULL 
    L->next = NULL;
    return last;
}

Status RlistFstack(Lnode*L){
	/*������Ԫ�����һ�����ݽڵ㣬����ʹ
	������Ԫ�ڵ�����ݽڵ���з�ת��������
	Ӱ�쵽��Ԫ���*/
	
	Lnode *p = L->next;
	Lnode *rear;
	rear = transpose(p);
	L->next = rear;
	return SUCCESS;
}

Lnode* FindNode(LinkedList L,int o){
	Lnode *p = L->next;
	int i = 1;
	//ͳ�����ݽڵ���� 
	while(p){
		i++;
		p = p->next;
	}
	//����Ϸ��ж� 
	if(o<1||o>i) {
		//printf("��Ŵ���\n");
		return NULL;
	}
	p = L->next;
	int j = 1;
	//���ض�Ӧ�ڵ� 
	while(j!=o){
		j++;
		p = p->next;
	}
	//��ֻ����Ԫ�ڵ���ڵ����⻯���� 
	if(o == 1&&L->next==NULL) return L;
	return p;
}

