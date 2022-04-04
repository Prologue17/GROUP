#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"sort.h"

void insertSort(int *a,int n){
	int i = 0;
	int t = 0;
	int j = 0; 
	for(i = 1; i < n; i++){
		//判断是否需要插入 
		if(a[i] < a[i-1]){
			//保存需要插入数据 
			t = a[i];
			//元素后移 
			a[i] = a[i-1];
			//依次后移找到插入位置 
			for(j = i - 1; t < a[j]; j--){
				if(j>=0)
					a[j+1] = a[j];
				else break;
			}
			//插入 
			a[j+1] = t;
		}
	}
}


void MergeArray(int *a,int begin,int mid,int end,int *temp){
	int i,j,k;
	i = begin; j = mid + 1; k = 0;
	//两串比较 将较小的数添至承载数组 
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
	//左串未空依次添至末尾 
	while(i <= mid ){
		temp[k] = a[i];
		k++; i++;
	}
	//右串未空依次添至末尾 
	while(j <= end){
		temp[k] = a[j];
		k++; j++;
	} 
	//保存已排序子序列 
	for (i = 0; i < k; i++)
		a[begin + i] = temp[i];
}


void MergeSort(int *a,int begin,int end,int *temp){
	int mid = 0;
	//递归退出 
	if(begin == end)
		;
	else{
		//求出中间数索引 
		mid = (begin + end) / 2;
		//对左子串递归拆解 
		MergeSort(a, begin, mid, temp);
		//对右子串递归拆解
		MergeSort(a, mid+1, end, temp);
		//递归合并排序 
		MergeArray(a, begin, mid, end, temp);
	}
}

void QuickSort_Recursion(int *a, int begin, int end){
	//判断是否是最短子串 
	if(begin < end){
		//中间位置索引 
		int pivotindex = 0;
		//使用枢轴将数组分为两个串 
		pivotindex = Partition(a, begin, end);
		//递归调用对左串分割排序 
		QuickSort_Recursion(a, begin, pivotindex - 1);
		//递归调用对右串分割排序 
		QuickSort_Recursion(a, pivotindex + 1, end); 
	}
}

int Partition(int *a, int begin, int end){
	//得到串的第一个元素作为枢轴 
	int pivot = a[begin];
	//左指针 
	int left = begin;
	//右指针 
	int right = end;
	//判断两指针是否相遇
	while(left < right){
		//从右往左寻找比枢轴小的元素 
		while(left < right && a[right] >= pivot)
			right--;
		//将小的数移至左边 
		a[left] = a[right];
		//从左往右寻找比枢轴大的元素
		while(left < right && a[left] <= pivot)
			left++;
		//将大的数移至右边 
		a[right] = a[left];
	}
	//将枢轴添至两指针相遇处 
	a[left] = pivot;
	//返回索引 
	return left;
}

void CountSort(int *a, int size , int max){
	int *b; int k = 0;
	//生成对应最大元素个数数组 
	b = (int*)malloc(sizeof(int) * (max + 1));
	int i = 0;
	//将数组元素全部置为0 
	for(i = 0; i <=max; i++){
		b[i] = 0;
	}
	//元素对应索引的值增加 
	for(i = 0; i < size; i++){
		b[a[i]]++;
	}
	//按顺序将计数数组变为数组 
	for(i = 0; i <= max; i++){
		int j = 0;
		//对应索引的元素个数对应几个元素 
		for(j = b[i]; j > 0; j--){
			a[k] = i;
			k++;
		}
	}
	free(b);
} 

int getpos(int num,int pos){
	//返回指定的位数的值 
	int i = 0; 
	//元素自除让指定的位数在最后一位 
	for(i = 0; i < pos-1; i++){
		num /=10;
	}
	//返回指定位数的值 
	return num%10;
} 



void RadixCountSort(int *a,int size){
 	int *array[10];
 	int i = 0;
 	int max = a[0];
 	//求出最大值 
 	for(i = 1; i < size; i++){
 		if(a[i] > max)
 			max = a[i];
	}
	//求出最大元素的位数 
	int numsize = 0;
	while(max){
		max /= 10;
		numsize++;
	}
	//生成二维数组作为桶 
 	for (i=0; i<10; i++){  
        array[i] = (int *)malloc(sizeof(int)*(size + 1));
		//以索引 0 的值记录当前位数上有几个元素  
        array[i][0] = 0;   
    }
    int j = 0;
    //按照位数的数量进行循环 
	for(i = 1; i <= numsize; i++){
		//将数组的元素入桶 
		for(j = 0; j <size ;j++){
			//得到数组中元素在当前指定位数的值 
			int num = getpos(a[j], i);
			//位数元素个数增加 同时便于插入数据 
			array[num][0]++;
			//得到数据个数 同时也作为插入元素的索引 
			int index = array[num][0];
			//按位数中的值插入数组中的元素到指定桶 
			array[num][index] = a[j];
		}
		j = 0;int k = 0; int x = 0;
		//进行出桶操作 
		for(x = 0;x < 10; x++){
			//按顺序对每个桶出桶到原数组 
			for(k = 1; k <= array[x][0]; k++){
				//出桶数据到原数组 
				a[j] = array[x][k];
				j++;
			}
			//将当前桶元素个数清0 便于下一次循环操作 
			array[x][0] = 0;
		}
	}
	for(i = 0; i <10 ;i++)
		free(array[i]);  
}

void ColorSort(int *a,int size){
	//遍历指针 p1  尾指针 p2
	//头指针 p0  交换临时变量 t 
	int p0 = 0; int p2 = size - 1;
	int p1 = 0; int  t = 0;
	//判断两指针是否相遇 
	while(p1 <= p2){
		//中间元素不移动 
		if(a[p1] == 1){
			p1++;
		}
		//小元素前移 
		else if(a[p1] == 0){
			//判断是否交换无效 
			if(a[p0] != 0){
			t = a[p1];
			a[p1] = a[p0];
			a[p0] = t;
			}
			//经过排序后前面数一定有序 
			//将两个指针前移 
			p1++;
			p0++;
		}
		//大元素后移 
		else if (a[p1] == 2){
			//判断尾指针位置是否为较小数是否能交换 
			if(a[p2] != 2){
			t = a[p1];
			a[p1] = a[p2];
			a[p2] = t;
			}
			//未发生交换尾指针前移即往前寻找可交换位置 
			//末尾元素大小未知
			//需要多进行一次判断 只将尾指针前移 
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
	//如果等于 k 返回 k 的值 
	if(left - begin + 1 == k) return a[left];
	// left 指针到起始点大于指定大小数 k
	//往左串进行查找到起始点为 k 的数 
	else if(left - begin + 1 > k ){
		return kfind(a,begin,left-1,k);
	}
	//left 指针到起始点小于指定大小数 k
	//说明第 k 个数在右串 对右串进行查找 
	else if(left - begin + 1 < k){
		// k 值更新为 k 减去左串已有数据个数 
		return kfind(a, left+1, end,k-left+begin-1);
	}
}

//保存数据 
int filesave(int *a, int size){
	FILE *fp = NULL;
	fp = fopen("data.txt","w");
	if(fp == NULL){
		printf("文件打开失败\n");
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


//读入数据 
int fileload(int *a,int num){
	FILE *fp = NULL;
	fp = fopen("data.txt","r");
	if(fp == NULL){
		printf("文件打开失败\n");
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
	printf("插入排序的用时是 %f\n",time);
	
	start = clock();
	for(i = 0; i < n; i++){
		a[i] = rand()%100;
	}
	MergeSort(a,0,n-1,temp);
	finish = clock();
	time = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("归并排序的用时是 %f\n",time);
	
	start = clock();
	for(i = 0; i < n; i++){
		a[i] = rand()%100;
	}
	QuickSort_Recursion(a, 0, n-1);
	finish = clock();
	time = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("快速排序的用时是 %f\n",time);
	
	start = clock();
	for(i = 0; i < n; i++){
		a[i] = rand()%100;
	}
	CountSort(a, n, 99);
	finish = clock();
	time = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("计数排序的用时是 %f\n",time);
	
	start = clock();
	for(i = 0; i < n; i++){
		a[i] = rand()%100;
	}
	RadixCountSort(a,n);
	finish = clock();
	time = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("基数排序的用时是 %f\n",time);
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
	printf("插入排序的用时是 %f\n",time);
	
	start = clock();
	for(i = 0; i < 10000;i++){
		for(j = 0; j < 100; j++){
			a[j] = rand()%100;
		}
		MergeSort(a,0,99,temp);
    }
    finish = clock();
	time = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("归并排序的用时是 %f\n",time);
	
	start = clock();
	for(i = 0; i < 10000;i++){
		for(j = 0; j < 100; j++){
			a[j] = rand()%100;
		}
		QuickSort_Recursion(a, 0, 99);
    }
    finish = clock();
	time = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("快速排序的用时是 %f\n",time);
	
	start = clock();
	for(i = 0; i < 10000;i++){
		for(j = 0; j < 100; j++){
			a[j] = rand()%100;
		}
		CountSort(a, 100, 99);
    }
    finish = clock();
	time = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("计数排序的用时是 %f\n",time);
	
	start = clock();
	for(i = 0; i < 10000;i++){
		for(j = 0; j < 100; j++){
			a[j] = rand()%100;
		}
		RadixCountSort(a,100);
    }
    finish = clock();
	time = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("基数排序的用时是 %f\n",time);
	//free(a);
	free(temp);
	//a = NULL;
}

int datacount(){
	//判断文件中的数据个数 
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
