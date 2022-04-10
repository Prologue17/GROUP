#include<stdio.h>
#include<stdlib.h>
#include"binary_sort_tree.h" 

void menu(){
	printf("输入 1 生成树\n");
	printf("输入 2 插入节点\n");
	printf("输入 3 删除节点\n");
	printf("输入 4 查询是否存在节点\n");
	printf("输入 5 递归前序遍历\n");
	printf("输入 6 递归中序遍历\n");
	printf("输入 7 递归后序遍历\n");
	printf("输入 8 非递归前序遍历\n");
	printf("输入 9 非递归中序遍历\n");
	printf("输入 a 非递归后序遍历\n");
	printf("输入 b 层次遍历\n");
	printf("输入 0 退出\n");
} 


int main(){
	BinarySortTreePtr T;
	T = (BinarySortTree*)malloc(sizeof(BinarySortTree));
	T->root = NULL; 
	char choice = '-1';
	int flag = -1;
	int e = -1;
	int i = -1;
	while(1){
		system("cls");
		menu();
		printf("输入你的选择：\n");
		fflush(stdin);
		scanf("%c", &choice);
		switch(choice){
				case '1':
						flag = BST_init(T);
						if(!flag){
							printf("创建失败\n");
						}
						else
							printf("创建成功\n");
						system("PAUSE");
						break;
						
				case '2':
						if(T->root == NULL){
							printf("无树\n");
							system("PAUSE");
							break;
						}
						printf("输入插入的数据\n");
						fflush(stdin);
						i = scanf("%d",&e);
						if(!i){
							printf("数据输入错误\n");
							system("PAUSE");
							break;
						}
						BST_insert(&T->root, e);
						system("PAUSE");
						break;
				
				case '3':
						if(T->root == NULL){
							printf("无树\n");
							system("PAUSE");
							break;
						}
						printf("输入需要删除的数据\n");
						fflush(stdin);
						i = scanf("%d",&e);
						if(!i){
							printf("数据输入错误\n");
							system("PAUSE");
							break;
						}
						BST_delete(&T->root, e);
						system("PAUSE");
						break;
						
				case '4':
						if(T->root == NULL){
							printf("无树\n");
							system("PAUSE");
							break;
						}
						printf("输入需要查询的数据\n");
						fflush(stdin);
						i = scanf("%d",&e);
						if(!i){
							printf("数据输入错误\n");
							system("PAUSE");
							break;
						}
						flag = BST_search(T->root, e);
						if(!flag){
							printf("不存在节点\n");
						}
						else
							printf("存在节点\n");
						system("PAUSE");
						break;
				
				case '5':
						if(T->root == NULL){
							printf("无树\n");
							system("PAUSE");
							break;
						}
						BST_preorderR(T->root, output);
						printf("\n");
						system("PAUSE");
						break;
				
				case '6':
						if(T->root == NULL){
							printf("无树\n");
							system("PAUSE");
							break;
						}
						BST_inorderR(T->root, output);
						printf("\n");
						system("PAUSE");
						break;
				
				case '7':
						if(T->root == NULL){
							printf("无树\n");
							system("PAUSE");
							break;
						}
						BST_postorderR(T->root, output);
						printf("\n");
						system("PAUSE");
						break;
				
				case '8':
						if(T->root == NULL){
							printf("无树\n");
							system("PAUSE");
							break;
						}
						BST_preorderI(T->root, output);
						printf("\n");
						system("PAUSE");
						break;
			
				case '9':
						if(T->root == NULL){
							printf("无树\n");
							system("PAUSE");
							break;
						}
						BST_inorderI(T->root, output);
						printf("\n");
						system("PAUSE");
						break;
						
				case 'a':
						if(T->root == NULL){
							printf("无树\n");
							system("PAUSE");
							break;
						}
						BST_postorderI(T->root, output);
						printf("\n");
						system("PAUSE");
						break;
				
				case 'b':
						if(T->root == NULL){
							printf("无树\n");
							system("PAUSE");
							break;
						}
						BST_levelOrder(T->root, output);
						printf("\n");
						system("PAUSE");
						break;
				
				case '0':
						return 0;
						break;
				
				default:
						printf("输入错误请重新错误\n");
						system("PAUSE");
						break;
		}
	} 
}


