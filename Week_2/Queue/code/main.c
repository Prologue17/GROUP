#include<stdio.h>
#include<stdlib.h>
#include "LQueue.h"

void menu(){
	printf("扣 1 创建队列\n");
	printf("扣 2 清空队列\n");
	printf("扣 3 销毁队列\n");
	printf("扣 4 判断队列是否为空\n");
	printf("扣 5 返回队首元素\n");
	printf("扣 6 返回队列长度\n");
	printf("扣 7 入队\n");
	printf("扣 8 出队\n");
	printf("扣 9 遍历队列\n");
	printf("扣 0 结束\n");
	printf("扣其他键送地狱火\n");
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
		printf("输入你的选择：");
		fflush(stdin); 
		scanf("%c",&choice);
		switch(choice){
			case '1':
					if(Q.front != NULL){
						printf("已有队列\n");
						system("PAUSE");
						break;
					}
					InitLQueue(&Q);
					printf("创建成功\n");
					system("PAUSE"); 
					break;
					
			case '2':
					i = IsEmptyLQueue(&Q);
					if(i == 0){
						system("PAUSE");
						break;
					}
					ClearLQueue(&Q);
					printf("清空成功\n");
					system("PAUSE");
					break;
					
			case '3':
					if(Q.front == NULL){
						printf("无队\n");
						system("PAUSE");
						break;
					}
					DestoryLQueue(&Q);
					printf("销毁成功\n");
					system("PAUSE");
					break;
					
			case '4':
					i = IsEmptyLQueue(&Q);
					if(!i){
						system("PAUSE");
						break;	
					}	
					printf("非空队列\n");
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
						printf("无队\n");
						system("PAUSE");
						break;
					}
					num = LengthLQueue(&Q);
					printf("队列的长度是 %d \n",num);
					system("PAUSE");
					break;
					
			case '7':
					if(Q.front == NULL){
						printf("无队\n");
						system("PAUSE");
						break;
					}
					//储存元素索引的数组满 
					if(Q.length == 30){
						printf("队列已满无法入队\n");
						system("PAUSE");
						break;
					} 
					
					printf("整型 输入 i 字符类型 输入 c 浮点型 输入 f \n");
					printf("输入你要入队的元素类型： \n");
					fflush(stdin);
					scanf("%c", &type);
					if(type != 'i' && type != 'c' && type != 'f'){
						printf("元素类型输入不合法\n");
						system("PAUSE");
						break;
					}
					
					if(type == 'i'){
						int *p;
						p = (int*)malloc(sizeof(int));
						printf("请输入你的数据： \n");
						fflush(stdin);
						i = scanf("%d",p);
						if(!i){
							printf("输入不合法\n");
							system("PAUSE");
							break;
						}
						e = p;
						EnLQueue(&Q, e);
						printf("入队成功\n");
						system("PAUSE");
						break; 
					}
					
					if(type == 'c'){
						char *p;
						p = (char*)malloc(sizeof(char));
						printf("请输入你的数据： \n");
						fflush(stdin);
						i = scanf("%c",p);
						if(!i){
							printf("输入不合法\n");
							system("PAUSE");
							break;
						}
						e = p;
						EnLQueue(&Q, e);
						printf("入队成功\n");
						system("PAUSE");
						break; 
					}
					
					if(type == 'f'){
						float *p;
						p = (float*)malloc(sizeof(float));
						printf("请输入你的数据： \n");
						fflush(stdin);
						i = scanf("%f",p);
						if(!i){
							printf("输入不合法\n");
							system("PAUSE");
							break;
						}
						e = p;
						EnLQueue(&Q, e);
						printf("入队成功\n");
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
					printf("111 真送吗哥\n");
					printf("请输入正确的序号\n");
					system("PAUSE");
					break;		
		}
	}
}
