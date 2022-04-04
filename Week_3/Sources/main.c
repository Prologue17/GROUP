#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"sort.h"

void menu(){
	printf("���� 1 ��� 60000 ������������ʱ\n");
	printf("���� 2 ��� 120000 ������������ʱ\n");
	printf("���� 3 ��� 180000 ������������ʱ\n");
	printf("���� 4 ��� 10000 �� 100 ������������ʱ\n");
	printf("���� 5 �����������������ļ���\n");
	printf("���� 6 ��������\n");
	printf("���� 7 �������\n");
	printf("���� 8 ʹ�ò�������\n");
	printf("���� 9 ʹ�ù鲢����\n");
	printf("���� a ʹ�ÿ�������\n");
	printf("���� b ʹ�ü�������\n");
	printf("���� c ʹ�û�������\n");
	printf("���� d �鿴��ɫ����Ч��\n");
	printf("���� e �鿴���ҵ���С����Ч��\n"); 
	printf("���� 0 �˳�\n");
}

int main(){
int i = 0;
char choice = '0'; 
int *a = NULL;
int num = 0;
int flag = 0;
int j = 0;
int max = 99;
int *b = NULL; 
while(1){
	system("cls");
	menu();
	printf("�������ѡ��: \n");
	fflush(stdin);
	scanf("%c",&choice);
	switch(choice){
		
		case '1':	
					printf("���ݵķ�Χ�� 0-99 ...\n");
					printf("�ȴ���...\n");
					testtime1(60000);
					a = NULL;
					system("PAUSE");
					break;
					
		case '2':	
					printf("���ݵķ�Χ�� 0-99 \n");
					printf("�ȴ���...\n");
					testtime1(120000);
					a = NULL;
					system("PAUSE");
					break;
					
		case '3':	
					printf("���ݵķ�Χ�� 0-99 ...\n");
					printf("�ȴ���...\n");
					testtime1(180000);
					a = NULL;
					system("PAUSE");
					break;
		
		case '4':	
					printf("���ݵķ�Χ�� 0-99 ...\n");
					printf("�ȴ���...\n");
					testtime2();
					a = NULL;
					system("PAUSE");
					break;
		
		case '5':	
					printf("��������Ҫ�����ļ������ݸ���: \n");
					fflush(stdin);
					flag = scanf("%d",&i);
					if(!flag){
						printf("�������\n");
						system("PAUSE");
						break;
					}
					a = (int*)malloc(i*sizeof(int));
					filesave(a, i); 
					free(a);
					a = NULL;
					system("PAUSE");
					break;
		
		case '6':	
					num = datacount();
					a = (int*)malloc(num*sizeof(int));
					FILE *fp = NULL;
					fp = fopen("data.txt","r");
					if(fp == NULL){
						printf("�ļ���ʧ��\n");
						system("PAUSE");
						break;
					}
					int i = 0;
					for(i = 0;i < num;i++){
						fscanf(fp,"%d ",&a[i]);
					}
					fclose(fp);
					printf("�������ݳɹ�\n");
					system("PAUSE");
					break;
		
		case '7':	
					if(a == NULL){
						printf("���ȵ�������\n");
						system("PAUSE");
						break; 
					}
					for(i = 0; i < num; i++){
						printf("%d ",a[i]);
					}
					printf("\n");
					printf("���µ��������Բ鿴����Ч��\n");
					system("PAUSE");
					break;
		
		case '8':	
					if(a == NULL){
						printf("���ȵ�������\n");
						system("PAUSE");
						break; 
					}
					insertSort(a,num);
					printf("����ɹ�\n");
					printf("ʹ��������ݿɲ鿴���\n");
					system("PAUSE");
					break;
		
		case '9':	{
					if(a == NULL){
						printf("���ȵ�������\n");
						system("PAUSE");
						break; 
					}
					int *temp;
					temp = (int*)malloc(num*sizeof(int)); 
					MergeSort(a, 0, num-1,temp);
					printf("����ɹ�\n");
					printf("ʹ��������ݿɲ鿴���\n");
					free(temp);
					system("PAUSE");
					break;
					}
					
		case 'a':
					if(a == NULL){
						printf("���ȵ�������\n");
						system("PAUSE");
						break; 
					}
					QuickSort_Recursion(a, 0, num-1);
					printf("����ɹ�\n");
					printf("ʹ��������ݿɲ鿴���\n");
					system("PAUSE");
					break;
					
		case 'b':
					if(a == NULL){
						printf("���ȵ�������\n");
						system("PAUSE");
						break; 
					}
					CountSort(a, num, max);
					printf("����ɹ�\n");
					printf("ʹ��������ݿɲ鿴���\n");
					system("PAUSE");
					break;
		
		case 'c':
					if(a == NULL){
						printf("���ȵ�������\n");
						system("PAUSE");
						break; 
					}
					RadixCountSort(a, num-1);
					printf("����ɹ�\n");
					printf("ʹ��������ݿɲ鿴���\n");
					system("PAUSE");
					break;
		
		case 'd':
					b = (int*)malloc(20*sizeof(int));
					for(i = 0; i < 20; i++)
						b[i] = rand()%3;
					printf("������ɵ�����: \n");
					for(i = 0; i < 20;i++)
						printf("%d ",b[i]);
					ColorSort(b,20);
					printf("����������: \n");
					for(i = 0; i < 20;i++)
						printf("%d ",b[i]);
					free(b);
					b = NULL;
					system("PAUSE");
					break;
		
		case 'e':
					b = (int*)malloc(20*sizeof(int));
					for(i = 0; i < 20; i++)
						b[i] = rand()%100;
					printf("������ɵ�����: \n");
					for(i = 0; i < 20;i++)
						printf("%d \n",b[i]);
					printf("����С�����ǣ�");
					i = kfind(b, 0, 19, 3);
					printf("%d\n",i);
					system("PAUSE");
					break;
					
		case '0':
					return 0;
					break;
		
		default:
					printf("�������\n");
					system("PAUSE");
					break; 
	}
} 
}
//int temp[10000];
//CountSort(a, 10000, 99);
//ColorSort(a,6);
//insertSort(a,10000);
//MergeSort(a,0,9999,temp);
//QuickSort_Recursion(a, 0, 9999);
//RadixCountSort(a,10000);
//i = kfind(a, 0, 14, 3);
//printf("%d", i);
