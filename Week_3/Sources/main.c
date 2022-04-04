#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"sort.h"

void menu(){
	printf("输入 1 输出 60000 个数据排序用时\n");
	printf("输入 2 输出 120000 个数据排序用时\n");
	printf("输入 3 输出 180000 个数据排序用时\n");
	printf("输入 4 输出 10000 次 100 个数据排序用时\n");
	printf("输入 5 随机生成数据添加至文件中\n");
	printf("输入 6 读入数据\n");
	printf("输入 7 输出数据\n");
	printf("输入 8 使用插入排序\n");
	printf("输入 9 使用归并排序\n");
	printf("输入 a 使用快速排序\n");
	printf("输入 b 使用计数排序\n");
	printf("输入 c 使用基数排序\n");
	printf("输入 d 查看颜色排序效果\n");
	printf("输入 e 查看查找第三小的数效果\n"); 
	printf("输入 0 退出\n");
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
	printf("输入你的选择: \n");
	fflush(stdin);
	scanf("%c",&choice);
	switch(choice){
		
		case '1':	
					printf("数据的范围是 0-99 ...\n");
					printf("等待中...\n");
					testtime1(60000);
					a = NULL;
					system("PAUSE");
					break;
					
		case '2':	
					printf("数据的范围是 0-99 \n");
					printf("等待中...\n");
					testtime1(120000);
					a = NULL;
					system("PAUSE");
					break;
					
		case '3':	
					printf("数据的范围是 0-99 ...\n");
					printf("等待中...\n");
					testtime1(180000);
					a = NULL;
					system("PAUSE");
					break;
		
		case '4':	
					printf("数据的范围是 0-99 ...\n");
					printf("等待中...\n");
					testtime2();
					a = NULL;
					system("PAUSE");
					break;
		
		case '5':	
					printf("请输入你要加入文件的数据个数: \n");
					fflush(stdin);
					flag = scanf("%d",&i);
					if(!flag){
						printf("输入错误\n");
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
						printf("文件打开失败\n");
						system("PAUSE");
						break;
					}
					int i = 0;
					for(i = 0;i < num;i++){
						fscanf(fp,"%d ",&a[i]);
					}
					fclose(fp);
					printf("导入数据成功\n");
					system("PAUSE");
					break;
		
		case '7':	
					if(a == NULL){
						printf("请先导入数据\n");
						system("PAUSE");
						break; 
					}
					for(i = 0; i < num; i++){
						printf("%d ",a[i]);
					}
					printf("\n");
					printf("重新导入数据以查看排序效果\n");
					system("PAUSE");
					break;
		
		case '8':	
					if(a == NULL){
						printf("请先导入数据\n");
						system("PAUSE");
						break; 
					}
					insertSort(a,num);
					printf("排序成功\n");
					printf("使用输出数据可查看结果\n");
					system("PAUSE");
					break;
		
		case '9':	{
					if(a == NULL){
						printf("请先导入数据\n");
						system("PAUSE");
						break; 
					}
					int *temp;
					temp = (int*)malloc(num*sizeof(int)); 
					MergeSort(a, 0, num-1,temp);
					printf("排序成功\n");
					printf("使用输出数据可查看结果\n");
					free(temp);
					system("PAUSE");
					break;
					}
					
		case 'a':
					if(a == NULL){
						printf("请先导入数据\n");
						system("PAUSE");
						break; 
					}
					QuickSort_Recursion(a, 0, num-1);
					printf("排序成功\n");
					printf("使用输出数据可查看结果\n");
					system("PAUSE");
					break;
					
		case 'b':
					if(a == NULL){
						printf("请先导入数据\n");
						system("PAUSE");
						break; 
					}
					CountSort(a, num, max);
					printf("排序成功\n");
					printf("使用输出数据可查看结果\n");
					system("PAUSE");
					break;
		
		case 'c':
					if(a == NULL){
						printf("请先导入数据\n");
						system("PAUSE");
						break; 
					}
					RadixCountSort(a, num-1);
					printf("排序成功\n");
					printf("使用输出数据可查看结果\n");
					system("PAUSE");
					break;
		
		case 'd':
					b = (int*)malloc(20*sizeof(int));
					for(i = 0; i < 20; i++)
						b[i] = rand()%3;
					printf("随机生成的数组: \n");
					for(i = 0; i < 20;i++)
						printf("%d ",b[i]);
					ColorSort(b,20);
					printf("排序后的数组: \n");
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
					printf("随机生成的数组: \n");
					for(i = 0; i < 20;i++)
						printf("%d \n",b[i]);
					printf("第三小的数是：");
					i = kfind(b, 0, 19, 3);
					printf("%d\n",i);
					system("PAUSE");
					break;
					
		case '0':
					return 0;
					break;
		
		default:
					printf("输入错误\n");
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
