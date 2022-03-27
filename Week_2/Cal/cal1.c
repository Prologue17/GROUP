#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//����ջ 
struct numstack{
	int num[50];
	int top;
	int rear;
};

//�ַ�ջ 
struct otstack{
	char ot[50];
	int top;
	int rear;
};

int main(){
	//��׺���ʽ 
	char a[50];
	//��׺���ʽ 
	char b[50];
	//����ջ��ʼ�� 
	struct numstack p;
	p.rear = 0;
	p.top = 0;
	//�ַ�ջ��ʼ�� 
	struct otstack q;
	q.ot[0] = '\0';
	q.top = 0;
	q.rear = 0;
	
	int i = 0;
	int lenb = 0;
	//������׺���ʽ 
	printf("������ʽ: \n");
	printf("��ʹ��Ӣ�����뷨����\n");
	printf("������ֻ���Ǹ�λ��\n"); 
	fflush(stdin);
	scanf("%s",a);
	//���ʽ���� 
	int len = strlen(a);
	//�ж������Ƿ�Ϸ� 
	for(i = 0; i < len; i++){
		//�жϸ�ʽ�Ƿ���ȷ 
		if(a[i] < '0'&&a[i] > '9'){
			if(a[i]!='+'&&a[i]!='-'&&a[i]!='*'&&a[i]!='/'&&a[i]!='('&&a[i]!=')'){
				printf("���벻�Ϸ�");
				return 0;
			}
		}
		//�ж��Ƿ��Ǹ�λ��������Ƿ���ȷ 
		if(i>0){
			if(a[i]>='0'&&a[i]<='9'&&a[i-1]>='0'&&a[i-1]<='9'){
				printf("ֻ�������λ������\n");
				return 0;
			}
			//�о���� 
			if(a[i-1]=='+'&&a[i]=='+'||a[i-1]=='+'&&a[i]=='-'||a[i-1]=='+'&&a[i]=='*'||a[i-1]=='+'&&a[i]=='/'||
			   a[i-1]=='-'&&a[i]=='+'||a[i-1]=='-'&&a[i]=='-'||a[i-1]=='-'&&a[i]=='*'||a[i-1]=='-'&&a[i]=='/'||
			   a[i-1]=='*'&&a[i]=='+'||a[i-1]=='*'&&a[i]=='-'||a[i-1]=='*'&&a[i]=='*'||a[i-1]=='*'&&a[i]=='/'||
			   a[i-1]=='/'&&a[i]=='+'||a[i-1]=='/'&&a[i]=='-'||a[i-1]=='/'&&a[i]=='*'||a[i-1]=='/'&&a[i]=='/'){
			   	
			   	printf("������Ŵ���\n");
			   	return 0;
			   }
		}
	}
	
	int cnt = 0;
	for(i = 0; i < len; i++){
		//����ֱ����� 
		if(a[i] >= '0' && a[i] <= '9'){
			b[cnt] = a[i];
			cnt++;
			continue;
		}
		//��������ջ 
		if(a[i] == '('){
			q.ot[q.top] = a[i];
			q.top++;
			continue;
		}
		//�����ų�ջֱ������������ 
		if(a[i] == ')'){
			while(q.ot[q.top-1] != '('){
				b[cnt] = q.ot[q.top-1];
				cnt++;
				q.top--;
			}
			q.top--;
			continue;
		}
		//�������ջֱ����ջ 
		if(q.rear == q.top){
			q.ot[q.top] = a[i];
			q.top++;
			continue;
		}
		
		//���ȼ������������ջ 
		if(q.ot[q.top-1] == '(' || q.ot[q.top-1] =='+'&&a[i] =='*' || 
		q.ot[q.top-1] =='+'&&a[i] =='/' ||q.ot[q.top-1] =='-'&&a[i] =='*'||
		q.ot[q.top-1] =='-'&&a[i] =='/'){
			q.ot[q.top] = a[i];
			q.top++;
		}
		
		else{
			//ջ����ջ 
			b[cnt] = q.ot[q.top-1];
			cnt++;
			q.top--;
			//��ջֱ���������ջ���� 
			//��Ϊ��ջ
			//��������� 
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
	//ջ��Ԫ�س�ջ 
	while(q.top!=q.rear){
		b[cnt] = q.ot[q.top-1];
		cnt++;
		q.top--;
	}
	lenb = strlen(b);
	printf("��׺���ʽ�ǣ� \n");
	//�����׺���ʽ 
	for(i = 0; i<lenb; i++){
		printf("%c",b[i]);
	}
	printf("\n");
	
	q.top = q.rear;
	int t1 = 0; int t2 = 0;
	int t = 0;
	for(i = 0; i < lenb; i++){
		//����������ջ 
		if(b[i] >= '0'&&b[i] <= '9'){
			p.num[p.top] = b[i]-48;
			p.top++;
		}
		//������������г�ջ����Ԫ�ص����� 
		//������ɺ�����ջ 
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
	//������ս�� 
	printf("����ǣ� \n");
	printf("%d",p.num[p.top-1]);
} 















