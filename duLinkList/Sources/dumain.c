#include<stdio.h>
#include<stdlib.h>
#include"duLinkedList.h"


int menu(){
	printf("�� 1 �����ڵ�\n");
	printf("�� 2 �������\n");
	printf("�� 3 ǰ��ڵ�\n");
	printf("�� 4 ���ڵ�\n");
	printf("�� 5 ɾ��ָ���ڵ�\n");
	printf("�� 6 ˳�����\n");
	printf("�� 7 �������\n");
	printf("�� 0 �˳�\n");
	printf("���������͵�����\n");
}



int main(){
	DuLinkedList L = NULL;
	int choice = -1;
	int i = -1;
	int o = -1;
	DuLNode *p = NULL;
	DuLNode *q = NULL;
	int e = -1;
	while(1){
		system("cls");
		menu();
		
		printf("enter your choice: ");
		scanf("%d",&choice);
		switch(choice){
			case 0:
					return 0;
					system("PAUSE");
					break;
					
			case 1:
					InitList_DuL(&L);
					system("PAUSE");
					break;
					
			case 2:
					if(!L){
						printf("������Ҫ�и��ڵ�...\n");
						break;
					}
					DestroyList_DuL(&L);
					system("PAUSE");
					break;
					
			case 3:
					if(!L){
						printf("������Ҫ�и��ڵ�...\n");
						break;
					}
					//�������������� 
					TraverseList_DuL(L, Spray);
					printf("����Ҫ������ڵ�����\n");
					scanf("%d",&o);
					//Ѱ��ָ������� 
					p = FindNode(L,o);
					if(!p) break;
					printf("������Ҫ����ڵ������\n");
					//��ʼ���ڵ� 
					q = (DuLNode *)malloc(sizeof(DuLNode));
					q->next = NULL;
					q->prior = NULL;
					scanf("%d",&q->data);
					//���ú��� 
					InsertBeforeList_DuL(p, q); 
					system("PAUSE");
					break;
					
			case 4:
					if(!L){
						printf("������Ҫ�и��ڵ�...\n");
						break;
					}
					//��������������
					TraverseList_DuL(L, Spray);
					printf("����Ҫ������ڵ�����\n");
					scanf("%d",&o);
					//Ѱ��ָ������� 
					p = FindNode(L,o);
					if(!p) break;
					printf("������Ҫ����ڵ������\n");
					//��ʼ���ڵ� 
					q = (DuLNode *)malloc(sizeof(DuLNode));
					q->next = NULL;
					q->prior = NULL;
					scanf("%d",&q->data);
					//���ú��� 
					InsertAfterList_DuL(p, q);
					system("PAUSE");
					break;
					
			case 5:
					if(!L){
						printf("������Ҫ�и��ڵ�...\n");
						break;
					}
					//��������������
					TraverseList_DuL(L, Spray);
					printf("����Ҫ��ɾ���Ľڵ��ǰһ����ţ���һ��Ϊ0��\n");
					scanf("%d",&o);
					//Ѱ��ָ�������
					p = FindNode(L,o); 
					if(!p) break;
					//���ú���ɾ�� 
					DeleteList_DuL(p, &e);
					printf("��ɾ���ڵ�������� %d ",e);
					system("PAUSE");
					break;
					
			case 6:
					if(!L){
						printf("������Ҫ�и��ڵ�...\n");
						break;
					}
					TraverseList_DuL(L, Spray);
					system("PAUSE");
					break;
			case 7:
					if(!L){
						printf("������Ҫ�и��ڵ�...\n");
						break;
					}
					PTraverseList_DuL(L, Spray);
					system("PAUSE");
					break;
					
			default:
					printf("��������\n");
					printf("��������ȷ������\n");
					system("PAUSE");
					break;
		}
	}
} 
