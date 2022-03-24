#include<stdio.h>
#include<stdlib.h>
#include"duLinkedList.h"


int menu(){
	printf("扣 1 创建节点\n");
	printf("扣 2 清空链表\n");
	printf("扣 3 前插节点\n");
	printf("扣 4 后插节点\n");
	printf("扣 5 删除指定节点\n");
	printf("扣 6 顺序遍历\n");
	printf("扣 7 后序遍历\n");
	printf("扣 0 退出\n");
	printf("扣其他键送地狱火\n");
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
						printf("你首先要有个节点...\n");
						break;
					}
					DestroyList_DuL(&L);
					system("PAUSE");
					break;
					
			case 3:
					if(!L){
						printf("你首先要有个节点...\n");
						break;
					}
					//遍历链表输出序号 
					TraverseList_DuL(L, Spray);
					printf("输入要被插入节点的序号\n");
					scanf("%d",&o);
					//寻找指定的序号 
					p = FindNode(L,o);
					if(!p) break;
					printf("输入你要插入节点的数据\n");
					//初始化节点 
					q = (DuLNode *)malloc(sizeof(DuLNode));
					q->next = NULL;
					q->prior = NULL;
					scanf("%d",&q->data);
					//调用函数 
					InsertBeforeList_DuL(p, q); 
					system("PAUSE");
					break;
					
			case 4:
					if(!L){
						printf("你首先要有个节点...\n");
						break;
					}
					//遍历链表输出序号
					TraverseList_DuL(L, Spray);
					printf("输入要被插入节点的序号\n");
					scanf("%d",&o);
					//寻找指定的序号 
					p = FindNode(L,o);
					if(!p) break;
					printf("输入你要插入节点的数据\n");
					//初始化节点 
					q = (DuLNode *)malloc(sizeof(DuLNode));
					q->next = NULL;
					q->prior = NULL;
					scanf("%d",&q->data);
					//调用函数 
					InsertAfterList_DuL(p, q);
					system("PAUSE");
					break;
					
			case 5:
					if(!L){
						printf("你首先要有个节点...\n");
						break;
					}
					//遍历链表输出序号
					TraverseList_DuL(L, Spray);
					printf("输入要被删除的节点的前一个序号（第一项为0）\n");
					scanf("%d",&o);
					//寻找指定的序号
					p = FindNode(L,o); 
					if(!p) break;
					//调用函数删除 
					DeleteList_DuL(p, &e);
					printf("被删除节点的数据是 %d ",e);
					system("PAUSE");
					break;
					
			case 6:
					if(!L){
						printf("你首先要有个节点...\n");
						break;
					}
					TraverseList_DuL(L, Spray);
					system("PAUSE");
					break;
			case 7:
					if(!L){
						printf("你首先要有个节点...\n");
						break;
					}
					PTraverseList_DuL(L, Spray);
					system("PAUSE");
					break;
					
			default:
					printf("真的送吗哥\n");
					printf("请输入正确的数字\n");
					system("PAUSE");
					break;
		}
	}
} 
