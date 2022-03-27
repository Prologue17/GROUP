#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include "LinkStack.h"

void menu(){
	printf("扣 1 创建栈\n");
	printf("扣 2 判断栈是否为空\n");
	printf("扣 3 得到栈顶元素\n");
	printf("扣 4 清空栈\n");
	printf("扣 5 销毁栈\n");
	printf("扣 6 检测栈长度\n");
	printf("扣 7 入栈\n");
	printf("扣 8 出栈\n");
	printf("扣 0 退出\n");
	printf("扣其他键送地狱火\n");
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
		printf("输入你的选择: ");
		fflush(stdin);
		scanf("%c",&choice);
		switch(choice){
			case '1':
					if(s.top!=NULL){
						printf("存在一个栈\n");
						system("PAUSE");
						break;
					}
					i = initLStack(&s);
					if(i == 1){
						printf("创建成功\n");
					}
					else
						printf("创建失败\n"); 
					system("PAUSE");
					break;
			
			case '2':
					i = isEmptyLStack(&s);
					if(i==1){
						printf("非空栈\n");
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
					printf("栈顶元素是 %d \n",e);
					system("PAUSE");
					break;
					
			case '4':
					i = isEmptyLStack(&s);
					if(i==0){
						system("PAUSE");
						break;
					}
					clearLStack(&s);
					printf("清空成功");
					system("PAUSE");
					break;
					
			case '5':
					if(s.top==NULL){
						printf("无栈\n");
						system("PAUSE");
						break;
					}
					destroyLStack(&s);
					printf("删除成功\n");
					system("PAUSE");
					break;
			
			case '6':
					if(s.top == NULL){
						printf("无栈\n");
						system("PAUSE");
						break;
					} 
					LStackLength(&s,&length);
					printf("栈的长度是 %d \n",length);
					system("PAUSE");
					break;
					
			case '7':
					if(s.top==NULL){
						printf("无栈\n");
						system("PAUSE");
						break;
					} 
					printf("输入数据\n");
					fflush(stdin); 
					//判断输入类型是否一致 
					i = scanf("%d",&data);
					if(!i){
						printf("输入不合法请输入整型数据\n");
						system("PAUSE");
						break; 
					}
					pushLStack(&s,data);
					printf("入栈成功\n");
					system("PAUSE");
					break;
			
			case '8':
					i = isEmptyLStack(&s);
					if(i==0){
						system("PAUSE");
						break;
					}
					popLStack(&s,&data);
					printf("被弹出的元素是 %d \n",data);
					system("PAUSE");
					break;
			
			case '0':
					destroyLStack(&s);
					return 0;
					break;
			
			default:
					printf("111真送吗哥\n");
					printf("请输入正确的序号\n");
					system("PAUSE");
					break;
		}
	} 
	return 0;
} 
