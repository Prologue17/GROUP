#include<stdio.h>
#include<stdlib.h>
#include"linkedList.h"


void menu(){
	printf("�� 1 �����ձ�\n");
	printf("�� 2 ��������\n");
	printf("�� 3 ����ڵ�\n");
	printf("�� 4 ɾ���ڵ�\n");
	printf("�� 5 ��������\n");
	printf("�� 6 ����ֵ��ѯ�ڵ�\n");
	printf("�� 7 ��ת����\n");
	printf("�� 8 ��ż�ڵ㽻��\n");
	printf("�� 9 �����м�ڵ�\n");
	printf("�� 0 �˳�\n");
	printf("���������͵�����\n");
} 


int main(){
	Lnode *L = NULL;
	int choice = -1;
	int tip = -1;
	int o = -1; 
	Lnode *p = NULL;
	Lnode *q = NULL;
	int e = -1; 
	while(1){
		system("cls");
		menu();
		printf("enter your choice: ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
					tip = InitList(&L);
					if(tip)
						printf("�����ɹ�\n");
					if(!tip)
						printf("����ʧ��\n");
					system("PAUSE");
					break;
				
			case 2:
					if(!L){
						printf("�����ȵ��и��ڵ�...\n");
						system("PAUSE");
						break;
					}
					DestroyList(&L);
					printf("�ɹ�\n");
					system("PAUSE");
					break;
					
			case 3:
					if(!L){
						printf("�����ȵ��и��ڵ�...\n");
						system("PAUSE");
						break;
					}
					//�������нڵ㹩ѡ����� 
					TraverseList(L, Spray);
					printf("������Ҫ������Ľڵ����\n");
					printf("����Ϸ�û������������ 1 ���в���\n");
					printf("�������ѡ�� ");
					scanf("%d",&o);
					//Ѱ�Ҷ�Ӧ�ڵ� 
					p = FindNode(L, o);
					if(!p){
						printf("�������\n");
						break;
					}
					//��ʼ���½ڵ� 
					q = (Lnode*)malloc(sizeof(Lnode));
					q->next = NULL;
					printf("������Ҫ����ڵ�����ݣ�\n");
					scanf("%d",&q->data);
					//���ú��� 
					InsertList(p, q);
					printf("�ɹ�\n");
					system("PAUSE");
					break;
					
			case 4:
					if(!L){
						printf("�����ȵ��и��ڵ�...\n");
						system("PAUSE");
						break;
					}
					//�������нڵ㹩ѡ����� 
					TraverseList(L, Spray);	
					printf("������Ҫ��ɾ���Ľڵ��ǰһ���ڵ����\n");
					scanf("%d",&o);	
					//Ѱ�Ҷ�Ӧ�ڵ� 
					p = FindNode(L, o);
					if(!p&&o!=0){
						printf("�������\n");
						break;
					}
					//ɾ����һ�����ݽڵ� 
					if(o == 0)
						p = L;
					//���ú��� 
					DeleteList(p, &e);
					printf("��ɾ���ڵ�������� %d \n",e);
					system("PAUSE");
					break;
					
			case 5:
					if(!L){
						printf("�����ȵ��и��ڵ�...\n");
						system("PAUSE");
						break;
					}
					TraverseList(L, Spray);
					system("PAUSE");
					break;
			
			case 6:
					if(!L){
						printf("�����ȵ��и��ڵ�...\n");
						system("PAUSE");
						break;
					}
					printf("������Ҫ���ҵ�ֵ\n");
					scanf("%d",&e);
					SearchList(L, e);
					system("PAUSE");
					break;
			
			case 7:
					if(!L){
						printf("�����ȵ��и��ڵ�...\n");
						system("PAUSE");
						break;
					}
					ReverseList(&L);
					printf("�ɹ�\n");
					system("PAUSE");
					break;
			
			case 8:
					if(!L){
						printf("�����ȵ��и��ڵ�...\n");
						system("PAUSE");
						break;
					}
					ReverseEvenList(&L);
					printf("�ɹ�\n");
					system("PAUSE");
					break;
			
			case 9:
					if(!L){
						printf("�����ȵ��и��ڵ�...\n");
						system("PAUSE");
						break;
					}
					p = FindMidNode(&L);
					printf("�м�ڵ�������� %d \n",p->data);
					system("PAUSE");
					break;
			
			case 0:
					DestroyList(&L);
					return 0;
					break;
					
			default:
					printf("��������\n");
					printf("��������ȷ�����\n");
					system("PAUSE");
					break;	
		}
	}
}
