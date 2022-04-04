#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"sort.h"

void insertSort(int *a,int n){
	int i = 0;
	int t = 0;
	int j = 0; 
	for(i = 1; i < n; i++){
		//�ж��Ƿ���Ҫ���� 
		if(a[i] < a[i-1]){
			//������Ҫ�������� 
			t = a[i];
			//Ԫ�غ��� 
			a[i] = a[i-1];
			//���κ����ҵ�����λ�� 
			for(j = i - 1; t < a[j]; j--){
				if(j>=0)
					a[j+1] = a[j];
				else break;
			}
			//���� 
			a[j+1] = t;
		}
	}
}


void MergeArray(int *a,int begin,int mid,int end,int *temp){
	int i,j,k;
	i = begin; j = mid + 1; k = 0;
	//�����Ƚ� ����С���������������� 
	while(i <= mid && j <= end){
		if(a[i] <= a[j]){
			temp[k] = a[i];
			k++; i++;
		}
		else{
			temp[k] = a[j];
			k++; j++;
		}
	}
	//��δ����������ĩβ 
	while(i <= mid ){
		temp[k] = a[i];
		k++; i++;
	}
	//�Ҵ�δ����������ĩβ 
	while(j <= end){
		temp[k] = a[j];
		k++; j++;
	} 
	//���������������� 
	for (i = 0; i < k; i++)
		a[begin + i] = temp[i];
}


void MergeSort(int *a,int begin,int end,int *temp){
	int mid = 0;
	//�ݹ��˳� 
	if(begin == end)
		;
	else{
		//����м������� 
		mid = (begin + end) / 2;
		//�����Ӵ��ݹ��� 
		MergeSort(a, begin, mid, temp);
		//�����Ӵ��ݹ���
		MergeSort(a, mid+1, end, temp);
		//�ݹ�ϲ����� 
		MergeArray(a, begin, mid, end, temp);
	}
}

void QuickSort_Recursion(int *a, int begin, int end){
	//�ж��Ƿ�������Ӵ� 
	if(begin < end){
		//�м�λ������ 
		int pivotindex = 0;
		//ʹ�����Ὣ�����Ϊ������ 
		pivotindex = Partition(a, begin, end);
		//�ݹ���ö��󴮷ָ����� 
		QuickSort_Recursion(a, begin, pivotindex - 1);
		//�ݹ���ö��Ҵ��ָ����� 
		QuickSort_Recursion(a, pivotindex + 1, end); 
	}
}

int Partition(int *a, int begin, int end){
	//�õ����ĵ�һ��Ԫ����Ϊ���� 
	int pivot = a[begin];
	//��ָ�� 
	int left = begin;
	//��ָ�� 
	int right = end;
	//�ж���ָ���Ƿ�����
	while(left < right){
		//��������Ѱ�ұ�����С��Ԫ�� 
		while(left < right && a[right] >= pivot)
			right--;
		//��С����������� 
		a[left] = a[right];
		//��������Ѱ�ұ�������Ԫ��
		while(left < right && a[left] <= pivot)
			left++;
		//������������ұ� 
		a[right] = a[left];
	}
	//������������ָ�������� 
	a[left] = pivot;
	//�������� 
	return left;
}

void CountSort(int *a, int size , int max){
	int *b; int k = 0;
	//���ɶ�Ӧ���Ԫ�ظ������� 
	b = (int*)malloc(sizeof(int) * (max + 1));
	int i = 0;
	//������Ԫ��ȫ����Ϊ0 
	for(i = 0; i <=max; i++){
		b[i] = 0;
	}
	//Ԫ�ض�Ӧ������ֵ���� 
	for(i = 0; i < size; i++){
		b[a[i]]++;
	}
	//��˳�򽫼��������Ϊ���� 
	for(i = 0; i <= max; i++){
		int j = 0;
		//��Ӧ������Ԫ�ظ�����Ӧ����Ԫ�� 
		for(j = b[i]; j > 0; j--){
			a[k] = i;
			k++;
		}
	}
	free(b);
} 

int getpos(int num,int pos){
	//����ָ����λ����ֵ 
	int i = 0; 
	//Ԫ���Գ���ָ����λ�������һλ 
	for(i = 0; i < pos-1; i++){
		num /=10;
	}
	//����ָ��λ����ֵ 
	return num%10;
} 



void RadixCountSort(int *a,int size){
 	int *array[10];
 	int i = 0;
 	int max = a[0];
 	//������ֵ 
 	for(i = 1; i < size; i++){
 		if(a[i] > max)
 			max = a[i];
	}
	//������Ԫ�ص�λ�� 
	int numsize = 0;
	while(max){
		max /= 10;
		numsize++;
	}
	//���ɶ�ά������ΪͰ 
 	for (i=0; i<10; i++){  
        array[i] = (int *)malloc(sizeof(int)*(size + 1));
		//������ 0 ��ֵ��¼��ǰλ�����м���Ԫ��  
        array[i][0] = 0;   
    }
    int j = 0;
    //����λ������������ѭ�� 
	for(i = 1; i <= numsize; i++){
		//�������Ԫ����Ͱ 
		for(j = 0; j <size ;j++){
			//�õ�������Ԫ���ڵ�ǰָ��λ����ֵ 
			int num = getpos(a[j], i);
			//λ��Ԫ�ظ������� ͬʱ���ڲ������� 
			array[num][0]++;
			//�õ����ݸ��� ͬʱҲ��Ϊ����Ԫ�ص����� 
			int index = array[num][0];
			//��λ���е�ֵ���������е�Ԫ�ص�ָ��Ͱ 
			array[num][index] = a[j];
		}
		j = 0;int k = 0; int x = 0;
		//���г�Ͱ���� 
		for(x = 0;x < 10; x++){
			//��˳���ÿ��Ͱ��Ͱ��ԭ���� 
			for(k = 1; k <= array[x][0]; k++){
				//��Ͱ���ݵ�ԭ���� 
				a[j] = array[x][k];
				j++;
			}
			//����ǰͰԪ�ظ�����0 ������һ��ѭ������ 
			array[x][0] = 0;
		}
	}
	for(i = 0; i <10 ;i++)
		free(array[i]);  
}

void ColorSort(int *a,int size){
	//����ָ�� p1  βָ�� p2
	//ͷָ�� p0  ������ʱ���� t 
	int p0 = 0; int p2 = size - 1;
	int p1 = 0; int  t = 0;
	//�ж���ָ���Ƿ����� 
	while(p1 <= p2){
		//�м�Ԫ�ز��ƶ� 
		if(a[p1] == 1){
			p1++;
		}
		//СԪ��ǰ�� 
		else if(a[p1] == 0){
			//�ж��Ƿ񽻻���Ч 
			if(a[p0] != 0){
			t = a[p1];
			a[p1] = a[p0];
			a[p0] = t;
			}
			//���������ǰ����һ������ 
			//������ָ��ǰ�� 
			p1++;
			p0++;
		}
		//��Ԫ�غ��� 
		else if (a[p1] == 2){
			//�ж�βָ��λ���Ƿ�Ϊ��С���Ƿ��ܽ��� 
			if(a[p2] != 2){
			t = a[p1];
			a[p1] = a[p2];
			a[p2] = t;
			}
			//δ��������βָ��ǰ�Ƽ���ǰѰ�ҿɽ���λ�� 
			//ĩβԪ�ش�Сδ֪
			//��Ҫ�����һ���ж� ֻ��βָ��ǰ�� 
			p2--;
		}
	}
}

int kfind(int *a, int begin, int end, int k){
	int pivot = a[begin];
	int left = begin;
	int right = end;
	while(left < right){
		while(left < right && a[right] >= pivot)
			right--;
		a[left] = a[right];
		while(left < right && a[left] <= pivot)
			left++;
		a[right] = a[left];
	}
	a[left] = pivot;
	//������� k ���� k ��ֵ 
	if(left - begin + 1 == k) return a[left];
	// left ָ�뵽��ʼ�����ָ����С�� k
	//���󴮽��в��ҵ���ʼ��Ϊ k ���� 
	else if(left - begin + 1 > k ){
		return kfind(a,begin,left-1,k);
	}
	//left ָ�뵽��ʼ��С��ָ����С�� k
	//˵���� k �������Ҵ� ���Ҵ����в��� 
	else if(left - begin + 1 < k){
		// k ֵ����Ϊ k ��ȥ���������ݸ��� 
		return kfind(a, left+1, end,k-left+begin-1);
	}
}

//�������� 
int filesave(int *a, int size){
	FILE *fp = NULL;
	fp = fopen("data.txt","w");
	if(fp == NULL){
		printf("�ļ���ʧ��\n");
		return 0;
	}
	int i = 0;
	int j = 0;
	//a = (int*)malloc(i*sizeof(int)); 
	for(j = 0; j < size;j++){
		a[j] = rand()%100;
	}
	for(i = 0; i < size ; i++){
		fprintf(fp,"%d ",a[i]);
	}
	fclose(fp);
	
}


//�������� 
int fileload(int *a,int num){
	FILE *fp = NULL;
	fp = fopen("data.txt","r");
	if(fp == NULL){
		printf("�ļ���ʧ��\n");
		return 0;
	}
	int i = 0;
	for(i = 0;i < num;i++){
		fscanf(fp,"%d ",&a[i]);
	}
	fclose(fp);
}

int testtime1(int n){
	int *a;
	a = (int*)malloc((n)*sizeof(int));
	clock_t start, finish;
	int *temp;
	temp = (int*)malloc(n*sizeof(int));
	int i = 0;
	double time;
	
	start = clock();
	for(i = 0; i < n; i++){
		a[i] = rand()%100;
	}
	insertSort(a,n);
	finish = clock();
	time = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("�����������ʱ�� %f\n",time);
	
	start = clock();
	for(i = 0; i < n; i++){
		a[i] = rand()%100;
	}
	MergeSort(a,0,n-1,temp);
	finish = clock();
	time = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("�鲢�������ʱ�� %f\n",time);
	
	start = clock();
	for(i = 0; i < n; i++){
		a[i] = rand()%100;
	}
	QuickSort_Recursion(a, 0, n-1);
	finish = clock();
	time = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("�����������ʱ�� %f\n",time);
	
	start = clock();
	for(i = 0; i < n; i++){
		a[i] = rand()%100;
	}
	CountSort(a, n, 99);
	finish = clock();
	time = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("�����������ʱ�� %f\n",time);
	
	start = clock();
	for(i = 0; i < n; i++){
		a[i] = rand()%100;
	}
	RadixCountSort(a,n);
	finish = clock();
	time = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("�����������ʱ�� %f\n",time);
	//free(a);
	free(temp);
	//a = NULL;
}

int testtime2(){
	int *a;
	a = (int*)malloc(100*sizeof(int));
	clock_t start, finish;
	int *temp;
	temp = (int*)malloc(100*sizeof(int));
	int i = 0; int j = 0;
	double time;
	
	start = clock();
	for(i = 0; i < 10000;i++){
		for(j = 0; j < 100; j++){
			a[j] = rand()%100;
		}
		insertSort(a,100);
    }
    finish = clock();
	time = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("�����������ʱ�� %f\n",time);
	
	start = clock();
	for(i = 0; i < 10000;i++){
		for(j = 0; j < 100; j++){
			a[j] = rand()%100;
		}
		MergeSort(a,0,99,temp);
    }
    finish = clock();
	time = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("�鲢�������ʱ�� %f\n",time);
	
	start = clock();
	for(i = 0; i < 10000;i++){
		for(j = 0; j < 100; j++){
			a[j] = rand()%100;
		}
		QuickSort_Recursion(a, 0, 99);
    }
    finish = clock();
	time = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("�����������ʱ�� %f\n",time);
	
	start = clock();
	for(i = 0; i < 10000;i++){
		for(j = 0; j < 100; j++){
			a[j] = rand()%100;
		}
		CountSort(a, 100, 99);
    }
    finish = clock();
	time = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("�����������ʱ�� %f\n",time);
	
	start = clock();
	for(i = 0; i < 10000;i++){
		for(j = 0; j < 100; j++){
			a[j] = rand()%100;
		}
		RadixCountSort(a,100);
    }
    finish = clock();
	time = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("�����������ʱ�� %f\n",time);
	//free(a);
	free(temp);
	//a = NULL;
}

int datacount(){
	//�ж��ļ��е����ݸ��� 
	FILE *fp;
	int i = 0;
	fp = fopen("data.txt","r");
	while(!feof(fp)){
		//fseek(fp,1,1);
		if(fgetc(fp) == ' ')
			i++;
		//printf("%d ",i);
	}
	//printf("%d",i);
	fclose(fp);
	return i;
}
