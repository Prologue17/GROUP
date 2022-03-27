#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include "LinkStack.h"

void menu(){
	printf("�� 1 ����ջ\n");
	printf("�� 2 �ж�ջ�Ƿ�Ϊ��\n");
	printf("�� 3 �õ�ջ��Ԫ��\n");
	printf("�� 4 ���ջ\n");
	printf("�� 5 ����ջ\n");
	printf("�� 6 ���ջ����\n");
	printf("�� 7 ��ջ\n");
	printf("�� 8 ��ջ\n");
	printf("�� 0 �˳�\n");
	printf("���������͵�����\n");
}

 
int main(){
	LinkStack s;
	s.top = NULL;
	s.count = 0;
	char choice = '-1';
	int i = -1;
	int e = -1;
	int length = -1;
	int data = -1; 
	while(1){
		system("cls");
		menu();
		printf("�������ѡ��: ");
		fflush(stdin);
		scanf("%c",&choice);
		switch(choice){
			case '1':
					if(s.top!=NULL){
						printf("����һ��ջ\n");
						system("PAUSE");
						break;
					}
					i = initLStack(&s);
					if(i == 1){
						printf("�����ɹ�\n");
					}
					else
						printf("����ʧ��\n"); 
					system("PAUSE");
					break;
			
			case '2':
					i = isEmptyLStack(&s);
					if(i==1){
						printf("�ǿ�ջ\n");
					}
					system("PAUSE");
					break;
					
			case '3':
					i = isEmptyLStack(&s);
					if(i == 0){
						system("PAUSE");
						break;
					}
					getTopLStack(&s,&e);
					printf("ջ��Ԫ���� %d \n",e);
					system("PAUSE");
					break;
					
			case '4':
					i = isEmptyLStack(&s);
					if(i==0){
						system("PAUSE");
						break;
					}
					clearLStack(&s);
					printf("��ճɹ�");
					system("PAUSE");
					break;
					
			case '5':
					if(s.top==NULL){
						printf("��ջ\n");
						system("PAUSE");
						break;
					}
					destroyLStack(&s);
					printf("ɾ���ɹ�\n");
					system("PAUSE");
					break;
			
			case '6':
					if(s.top == NULL){
						printf("��ջ\n");
						system("PAUSE");
						break;
					} 
					LStackLength(&s,&length);
					printf("ջ�ĳ����� %d \n",length);
					system("PAUSE");
					break;
					
			case '7':
					if(s.top==NULL){
						printf("��ջ\n");
						system("PAUSE");
						break;
					} 
					printf("��������\n");
					fflush(stdin); 
					//�ж����������Ƿ�һ�� 
					i = scanf("%d",&data);
					if(!i){
						printf("���벻�Ϸ���������������\n");
						system("PAUSE");
						break; 
					}
					pushLStack(&s,data);
					printf("��ջ�ɹ�\n");
					system("PAUSE");
					break;
			
			case '8':
					i = isEmptyLStack(&s);
					if(i==0){
						system("PAUSE");
						break;
					}
					popLStack(&s,&data);
					printf("��������Ԫ���� %d \n",data);
					system("PAUSE");
					break;
			
			case '0':
					destroyLStack(&s);
					return 0;
					break;
			
			default:
					printf("111�������\n");
					printf("��������ȷ�����\n");
					system("PAUSE");
					break;
		}
	} 
	return 0;
} 
