#include<stdio.h>
#include<stdlib.h>
#include"linkedList.h"


void menu(){
	printf("扣 1 创建空表\n");
	printf("扣 2 销毁链表\n");
	printf("扣 3 插入节点\n");
	printf("扣 4 删除节点\n");
	printf("扣 5 遍历链表\n");
	printf("扣 6 根据值查询节点\n");
	printf("扣 7 反转链表\n");
	printf("扣 8 奇偶节点交换\n");
	printf("扣 9 返回中间节点\n");
	printf("扣 0 退出\n");
	printf("扣其他键送地狱火\n");
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
						printf("创建成功\n");
					if(!tip)
						printf("创建失败\n");
					system("PAUSE");
					break;
				
			case 2:
					if(!L){
						printf("你首先得有个节点...\n");
						system("PAUSE");
						break;
					}
					DestroyList(&L);
					printf("成功\n");
					system("PAUSE");
					break;
					
			case 3:
					if(!L){
						printf("你首先得有个节点...\n");
						system("PAUSE");
						break;
					}
					//遍历已有节点供选择序号 
					TraverseList(L, Spray);
					printf("输入你要被插入的节点序号\n");
					printf("如果上方没有数据则输入 1 进行插入\n");
					printf("输入你的选择： ");
					scanf("%d",&o);
					//寻找对应节点 
					p = FindNode(L, o);
					if(!p){
						printf("输入错误\n");
						break;
					}
					//初始化新节点 
					q = (Lnode*)malloc(sizeof(Lnode));
					q->next = NULL;
					printf("输入你要插入节点的数据：\n");
					scanf("%d",&q->data);
					//调用函数 
					InsertList(p, q);
					printf("成功\n");
					system("PAUSE");
					break;
					
			case 4:
					if(!L){
						printf("你首先得有个节点...\n");
						system("PAUSE");
						break;
					}
					//遍历已有节点供选择序号 
					TraverseList(L, Spray);	
					printf("输入你要被删除的节点的前一个节点序号\n");
					scanf("%d",&o);	
					//寻找对应节点 
					p = FindNode(L, o);
					if(!p&&o!=0){
						printf("输入错误\n");
						break;
					}
					//删除第一个数据节点 
					if(o == 0)
						p = L;
					//调用函数 
					DeleteList(p, &e);
					printf("你删除节点的数据是 %d \n",e);
					system("PAUSE");
					break;
					
			case 5:
					if(!L){
						printf("你首先得有个节点...\n");
						system("PAUSE");
						break;
					}
					TraverseList(L, Spray);
					system("PAUSE");
					break;
			
			case 6:
					if(!L){
						printf("你首先得有个节点...\n");
						system("PAUSE");
						break;
					}
					printf("输入你要查找的值\n");
					scanf("%d",&e);
					SearchList(L, e);
					system("PAUSE");
					break;
			
			case 7:
					if(!L){
						printf("你首先得有个节点...\n");
						system("PAUSE");
						break;
					}
					ReverseList(&L);
					printf("成功\n");
					system("PAUSE");
					break;
			
			case 8:
					if(!L){
						printf("你首先得有个节点...\n");
						system("PAUSE");
						break;
					}
					ReverseEvenList(&L);
					printf("成功\n");
					system("PAUSE");
					break;
			
			case 9:
					if(!L){
						printf("你首先得有个节点...\n");
						system("PAUSE");
						break;
					}
					p = FindMidNode(&L);
					printf("中间节点的数据是 %d \n",p->data);
					system("PAUSE");
					break;
			
			case 0:
					DestroyList(&L);
					return 0;
					break;
					
			default:
					printf("真的送吗哥\n");
					printf("请输入正确的序号\n");
					system("PAUSE");
					break;	
		}
	}
}
