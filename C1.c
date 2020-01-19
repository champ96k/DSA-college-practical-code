#include<stdio.h>
struct stack
{
	char s[30];
	int top;
}st;
void main()
{
	char infix[30];
	void intoport(char infix [30]);
	printf("\n enter the infix expression\n\n");
	scanf("%s",infix);
	intoport(infix);
}
void intoport(char infix[30])
{
	st.top=-1;
	st.top=st.top+1;
	st.s[st.top]='$';
	char postfix[30];
	int i,j;
	char ch;
	int instack(char ch);
	int incoming(char ch);
	void push(char item);
	char pop();
	i=0;
	for(i=0;infix[i]!='\0';i++)
	{
		ch=infix[i];
		while(instack(st.s[st.top])>incoming(ch))
		{
			postfix[j]=pop();
			j++;
		}
		if(instack(st.s[st.top])!=incoming(ch))
		 push(ch);
		 else
		 pop();
	}
	while(ch=pop()!='$')
	{
		postfix[j]=ch;
		j++;
	}
	postfix[j]='\0';
	printf("\n The postfix expresstion is => %s",postfix);
}
int instack(char ch)
{
	 int priority;
	 switch(ch)
	 {
	    case '+':
	    case '-': priority=2;
	    break;
		case'*':
		case'/': priority=4;
		break;
		case '^': priority=6;
		break;
		case '(': priority=0;
		break; 
		case '$': priority=-1;
		break;
		default: priority=8;
	 }
	 return priority;
}

int incoming(char ch)
{
	int priority;
	switch(ch)
	{
		 case '+':
	    case '-': priority=1;
	    break;
		case '*':
		case'/': priority=3;
		break;
		case '^': priority=6;
		break;
		case '(': priority=9;
		break; 
		case ')': priority=0;
		break;
		default: priority=7;
	}
	return priority;
}
void push(char item)
{
	st.top++;
	st.s[st.top]=item;
}
char pop()
{
	char e;
	e=st.s[st.top];
	st.top--;
	return e;
}
