#include<stdio.h>
#include<stdlib.h>
#include "LQueue.h"

void menu(){
	printf("�� 1 ��������\n");
	printf("�� 2 ��ն���\n");
	printf("�� 3 ���ٶ���\n");
	printf("�� 4 �ж϶����Ƿ�Ϊ��\n");
	printf("�� 5 ���ض���Ԫ��\n");
	printf("�� 6 ���ض��г���\n");
	printf("�� 7 ���\n");
	printf("�� 8 ����\n");
	printf("�� 9 ��������\n");
	printf("�� 0 ����\n");
	printf("���������͵�����\n");
}

int main(){
	LQueue Q;
	Q.front = NULL;
	Q.rear = NULL;
	Q.length = 0;
	char choice = '-1';
	int i = -1;
	void *e = NULL; 
	int num = -1;
	while(1){
		system("cls");
		menu();
		printf("�������ѡ��");
		fflush(stdin); 
		scanf("%c",&choice);
		switch(choice){
			case '1':
					if(Q.front != NULL){
						printf("���ж���\n");
						system("PAUSE");
						break;
					}
					InitLQueue(&Q);
					printf("�����ɹ�\n");
					system("PAUSE"); 
					break;
					
			case '2':
					i = IsEmptyLQueue(&Q);
					if(i == 0){
						system("PAUSE");
						break;
					}
					ClearLQueue(&Q);
					printf("��ճɹ�\n");
					system("PAUSE");
					break;
					
			case '3':
					if(Q.front == NULL){
						printf("�޶�\n");
						system("PAUSE");
						break;
					}
					DestoryLQueue(&Q);
					printf("���ٳɹ�\n");
					system("PAUSE");
					break;
					
			case '4':
					i = IsEmptyLQueue(&Q);
					if(!i){
						system("PAUSE");
						break;	
					}	
					printf("�ǿն���\n");
					system("PAUSE");
					break;
			
			case '5':
					i = IsEmptyLQueue(&Q);
					if(!i){
						system("PAUSE");
						break;	
					}
					GetHeadLQueue(&Q, &e);
					LPrint(e, 0);
					system("PAUSE");
					break;
					
			case '6':
					if(Q.front == NULL){
						printf("�޶�\n");
						system("PAUSE");
						break;
					}
					num = LengthLQueue(&Q);
					printf("���еĳ����� %d \n",num);
					system("PAUSE");
					break;
					
			case '7':
					if(Q.front == NULL){
						printf("�޶�\n");
						system("PAUSE");
						break;
					}
					//����Ԫ�������������� 
					if(Q.length == 30){
						printf("���������޷����\n");
						system("PAUSE");
						break;
					} 
					
					printf("���� ���� i �ַ����� ���� c ������ ���� f \n");
					printf("������Ҫ��ӵ�Ԫ�����ͣ� \n");
					fflush(stdin);
					scanf("%c", &type);
					if(type != 'i' && type != 'c' && type != 'f'){
						printf("Ԫ���������벻�Ϸ�\n");
						system("PAUSE");
						break;
					}
					
					if(type == 'i'){
						int *p;
						p = (int*)malloc(sizeof(int));
						printf("������������ݣ� \n");
						fflush(stdin);
						i = scanf("%d",p);
						if(!i){
							printf("���벻�Ϸ�\n");
							system("PAUSE");
							break;
						}
						e = p;
						EnLQueue(&Q, e);
						printf("��ӳɹ�\n");
						system("PAUSE");
						break; 
					}
					
					if(type == 'c'){
						char *p;
						p = (char*)malloc(sizeof(char));
						printf("������������ݣ� \n");
						fflush(stdin);
						i = scanf("%c",p);
						if(!i){
							printf("���벻�Ϸ�\n");
							system("PAUSE");
							break;
						}
						e = p;
						EnLQueue(&Q, e);
						printf("��ӳɹ�\n");
						system("PAUSE");
						break; 
					}
					
					if(type == 'f'){
						float *p;
						p = (float*)malloc(sizeof(float));
						printf("������������ݣ� \n");
						fflush(stdin);
						i = scanf("%f",p);
						if(!i){
							printf("���벻�Ϸ�\n");
							system("PAUSE");
							break;
						}
						e = p;
						EnLQueue(&Q, e);
						printf("��ӳɹ�\n");
						system("PAUSE");
						break; 
					}
					break;	
					
			case '8':
					i = IsEmptyLQueue(&Q);
					if(!i){
						system("PAUSE");
						break;	
					}
					DeLQueue(&Q);
					
					system("PAUSE");
					break;
			
			case '9':
					i = IsEmptyLQueue(&Q);
					if(!i){
						system("PAUSE");
						break;	
					}
					TraverseLQueue(&Q, LPrint);
					system("PAUSE");
					break;
			
			case '0':
					DestoryLQueue(&Q);
					return 0;
					break;
					
			default:
					printf("111 �������\n");
					printf("��������ȷ�����\n");
					system("PAUSE");
					break;		
		}
	}
}
