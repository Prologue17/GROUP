#include<stdio.h>
#include<stdlib.h>
#include"binary_sort_tree.h" 

void menu(){
	printf("���� 1 ������\n");
	printf("���� 2 ����ڵ�\n");
	printf("���� 3 ɾ���ڵ�\n");
	printf("���� 4 ��ѯ�Ƿ���ڽڵ�\n");
	printf("���� 5 �ݹ�ǰ�����\n");
	printf("���� 6 �ݹ��������\n");
	printf("���� 7 �ݹ�������\n");
	printf("���� 8 �ǵݹ�ǰ�����\n");
	printf("���� 9 �ǵݹ��������\n");
	printf("���� a �ǵݹ�������\n");
	printf("���� b ��α���\n");
	printf("���� 0 �˳�\n");
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
		printf("�������ѡ��\n");
		fflush(stdin);
		scanf("%c", &choice);
		switch(choice){
				case '1':
						flag = BST_init(T);
						if(!flag){
							printf("����ʧ��\n");
						}
						else
							printf("�����ɹ�\n");
						system("PAUSE");
						break;
						
				case '2':
						if(T->root == NULL){
							printf("����\n");
							system("PAUSE");
							break;
						}
						printf("������������\n");
						fflush(stdin);
						i = scanf("%d",&e);
						if(!i){
							printf("�����������\n");
							system("PAUSE");
							break;
						}
						BST_insert(&T->root, e);
						system("PAUSE");
						break;
				
				case '3':
						if(T->root == NULL){
							printf("����\n");
							system("PAUSE");
							break;
						}
						printf("������Ҫɾ��������\n");
						fflush(stdin);
						i = scanf("%d",&e);
						if(!i){
							printf("�����������\n");
							system("PAUSE");
							break;
						}
						BST_delete(&T->root, e);
						system("PAUSE");
						break;
						
				case '4':
						if(T->root == NULL){
							printf("����\n");
							system("PAUSE");
							break;
						}
						printf("������Ҫ��ѯ������\n");
						fflush(stdin);
						i = scanf("%d",&e);
						if(!i){
							printf("�����������\n");
							system("PAUSE");
							break;
						}
						flag = BST_search(T->root, e);
						if(!flag){
							printf("�����ڽڵ�\n");
						}
						else
							printf("���ڽڵ�\n");
						system("PAUSE");
						break;
				
				case '5':
						if(T->root == NULL){
							printf("����\n");
							system("PAUSE");
							break;
						}
						BST_preorderR(T->root, output);
						printf("\n");
						system("PAUSE");
						break;
				
				case '6':
						if(T->root == NULL){
							printf("����\n");
							system("PAUSE");
							break;
						}
						BST_inorderR(T->root, output);
						printf("\n");
						system("PAUSE");
						break;
				
				case '7':
						if(T->root == NULL){
							printf("����\n");
							system("PAUSE");
							break;
						}
						BST_postorderR(T->root, output);
						printf("\n");
						system("PAUSE");
						break;
				
				case '8':
						if(T->root == NULL){
							printf("����\n");
							system("PAUSE");
							break;
						}
						BST_preorderI(T->root, output);
						printf("\n");
						system("PAUSE");
						break;
			
				case '9':
						if(T->root == NULL){
							printf("����\n");
							system("PAUSE");
							break;
						}
						BST_inorderI(T->root, output);
						printf("\n");
						system("PAUSE");
						break;
						
				case 'a':
						if(T->root == NULL){
							printf("����\n");
							system("PAUSE");
							break;
						}
						BST_postorderI(T->root, output);
						printf("\n");
						system("PAUSE");
						break;
				
				case 'b':
						if(T->root == NULL){
							printf("����\n");
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
						printf("������������´���\n");
						system("PAUSE");
						break;
		}
	} 
}


