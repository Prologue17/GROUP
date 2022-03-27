#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct numstack{
	int num[50];
	int top;
	int rear;
};

struct otstack{
	char ot[50];
	int top;
	int rear;
};

int main(){
	char a[50];
	char b[50];
	struct numstack p;
	p.rear = 0;
	p.top = 0;
	struct otstack q;
	q.ot[0] = '\0';
	q.top = 0;
	q.rear = 0;
	int i = 0;
	int lenb = 0;
	printf("输入表达式: \n");
	printf("请使用英文输入法输入\n");
	printf("运算数只能是个位数\n"); 
	fflush(stdin);
	scanf("%s",a);
	int len = strlen(a);
	for(i = 0; i < len; i++){
		if(a[i] < '0'&&a[i] > '9'){
			if(a[i]!='+'&&a[i]!='-'&&a[i]!='*'&&a[i]!='/'&&a[i]!='('&&a[i]!=')'){
				printf("输入不合法");
				return 0;
			}
		}
		if(i>0){
			if(a[i]<='0'&&a[i]<='9'&&a[i-1]<='0'&&a[i-1]<='9'){
				printf("只能输入个位数运算\n");
				return 0;
			}
			if(a[i-1]=='+'&&a[i]=='+'||a[i-1]=='+'&&a[i]=='-'||a[i-1]=='+'&&a[i]=='*'||a[i-1]=='+'&&a[i]=='/'||
			   a[i-1]=='-'&&a[i]=='+'||a[i-1]=='-'&&a[i]=='-'||a[i-1]=='-'&&a[i]=='*'||a[i-1]=='-'&&a[i]=='/'||
			   a[i-1]=='*'&&a[i]=='+'||a[i-1]=='*'&&a[i]=='-'||a[i-1]=='*'&&a[i]=='*'||a[i-1]=='*'&&a[i]=='/'||
			   a[i-1]=='/'&&a[i]=='+'||a[i-1]=='/'&&a[i]=='-'||a[i-1]=='/'&&a[i]=='*'||a[i-1]=='/'&&a[i]=='/'){
			   	
			   	printf("输入符号错误\n");
			   	return 0;
			   }
		}
	}
	int cnt = 0;
	for(i = 0; i < len; i++){
		if(a[i] >= '0' && a[i] <= '9'){
			b[cnt] = a[i];
			cnt++;
			continue;
		}
		if(a[i] == '('){
			q.ot[q.top] = a[i];
			q.top++;
			continue;
		}
		if(a[i] == ')'){
			while(q.ot[q.top-1] != '('){
				b[cnt] = q.ot[q.top-1];
				cnt++;
				q.top--;
			}
			q.top--;
			continue;
		}
		if(q.rear == q.top){
			q.ot[q.top] = a[i];
			q.top++;
			continue;
		}
		
		
		if(q.ot[q.top-1] == '(' || q.ot[q.top-1] =='+'&&a[i] =='*' || 
		q.ot[q.top-1] =='+'&&a[i] =='/' ||q.ot[q.top-1] =='-'&&a[i] =='*'||
		q.ot[q.top-1] =='-'&&a[i] =='/'){
			q.ot[q.top] = a[i];
			q.top++;
		}
		
		else{
			b[cnt] = q.ot[q.top-1];
			cnt++;
			q.top--;
			while(q.top != q.rear&&q.ot[q.top-1]!='('&&
			(a[i] == '+'||a[i] == '-'||a[i] == '*'&&q.ot[q.top-1] !='+'||
			a[i] == '*'&&q.ot[q.top-1] !='-'||a[i] == '/'&&q.ot[q.top-1] !='+'||
			a[i] == '/'&&q.ot[q.top-1] !='-')){
				
			b[cnt] = q.ot[q.top-1];
			cnt++;
			q.top--;
		}
		q.ot[q.top] = a[i];
		q.top++;
		}
	}
	while(q.top!=q.rear){
		b[cnt] = q.ot[q.top-1];
		cnt++;
		q.top--;
	}
	lenb = strlen(b);
	printf("后缀表达式是： \n");
	for(i = 0; i<lenb; i++){
		printf("%c",b[i]);
	}
	printf("\n");
	
	q.top = q.rear;
	int t1 = 0; int t2 = 0;
	int t = 0;
	for(i = 0; i < lenb; i++){
		if(b[i] >= '0'&&b[i] <= '9'){
			p.num[p.top] = b[i]-48;
			p.top++;
		}
		if(b[i] == '+'){
			t1 = p.num[p.top-1];
			p.top--;
			t2 = p.num[p.top-1];
			p.top--;
			t = t2 + t1;
			p.num[p.top] = t;
			p.top++;
		}
		if(b[i] == '-'){
			t1 = p.num[p.top-1];
			p.top--;
			t2 = p.num[p.top-1];
			p.top--;
			t = t2 - t1;
			p.num[p.top] = t;
			p.top++;
		}
		if(b[i] == '*'){
			t1 = p.num[p.top-1];
			p.top--;
			t2 = p.num[p.top-1];
			p.top--;
			t = t2 * t1;
			p.num[p.top] = t;
			p.top++;
		}
		if(b[i] == '/'){
			t1 = p.num[p.top-1];
			p.top--;
			t2 = p.num[p.top-1];
			p.top--;
			t = t2 / t1;
			p.num[p.top] = t;
			p.top++;
		}
	}
	printf("结果是： \n");
	printf("%d",p.num[p.top-1]);
} 















