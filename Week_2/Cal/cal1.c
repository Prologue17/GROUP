#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//数字栈 
struct numstack{
	int num[50];
	int top;
	int rear;
};

//字符栈 
struct otstack{
	char ot[50];
	int top;
	int rear;
};

int main(){
	//中缀表达式 
	char a[50];
	//后缀表达式 
	char b[50];
	//数字栈初始化 
	struct numstack p;
	p.rear = 0;
	p.top = 0;
	//字符栈初始化 
	struct otstack q;
	q.ot[0] = '\0';
	q.top = 0;
	q.rear = 0;
	
	int i = 0;
	int lenb = 0;
	//接收中缀表达式 
	printf("输入表达式: \n");
	printf("请使用英文输入法输入\n");
	printf("运算数只能是个位数\n"); 
	fflush(stdin);
	scanf("%s",a);
	//表达式长度 
	int len = strlen(a);
	//判断输入是否合法 
	for(i = 0; i < len; i++){
		//判断格式是否正确 
		if(a[i] < '0'&&a[i] > '9'){
			if(a[i]!='+'&&a[i]!='-'&&a[i]!='*'&&a[i]!='/'&&a[i]!='('&&a[i]!=')'){
				printf("输入不合法");
				return 0;
			}
		}
		//判断是否是个位数或符号是否正确 
		if(i>0){
			if(a[i]>='0'&&a[i]<='9'&&a[i-1]>='0'&&a[i-1]<='9'){
				printf("只能输入个位数运算\n");
				return 0;
			}
			//列举情况 
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
		//数字直接输出 
		if(a[i] >= '0' && a[i] <= '9'){
			b[cnt] = a[i];
			cnt++;
			continue;
		}
		//左括号入栈 
		if(a[i] == '('){
			q.ot[q.top] = a[i];
			q.top++;
			continue;
		}
		//右括号出栈直到遇到左括号 
		if(a[i] == ')'){
			while(q.ot[q.top-1] != '('){
				b[cnt] = q.ot[q.top-1];
				cnt++;
				q.top--;
			}
			q.top--;
			continue;
		}
		//运算符空栈直接入栈 
		if(q.rear == q.top){
			q.ot[q.top] = a[i];
			q.top++;
			continue;
		}
		
		//优先级打或左括号入栈 
		if(q.ot[q.top-1] == '(' || q.ot[q.top-1] =='+'&&a[i] =='*' || 
		q.ot[q.top-1] =='+'&&a[i] =='/' ||q.ot[q.top-1] =='-'&&a[i] =='*'||
		q.ot[q.top-1] =='-'&&a[i] =='/'){
			q.ot[q.top] = a[i];
			q.top++;
		}
		
		else{
			//栈顶出栈 
			b[cnt] = q.ot[q.top-1];
			cnt++;
			q.top--;
			//出栈直到运算符比栈顶大 
			//不为空栈
			//不输出括号 
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
	//栈中元素出栈 
	while(q.top!=q.rear){
		b[cnt] = q.ot[q.top-1];
		cnt++;
		q.top--;
	}
	lenb = strlen(b);
	printf("后缀表达式是： \n");
	//输出后缀表达式 
	for(i = 0; i<lenb; i++){
		printf("%c",b[i]);
	}
	printf("\n");
	
	q.top = q.rear;
	int t1 = 0; int t2 = 0;
	int t = 0;
	for(i = 0; i < lenb; i++){
		//遇到数字入栈 
		if(b[i] >= '0'&&b[i] <= '9'){
			p.num[p.top] = b[i]-48;
			p.top++;
		}
		//遇到运算符进行出栈两个元素的运算 
		//计算完成后再入栈 
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
	//输出最终结果 
	printf("结果是： \n");
	printf("%d",p.num[p.top-1]);
} 















