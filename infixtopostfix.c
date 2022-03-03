#include<stdio.h>
#include<string.h>
#include<ctype.h>
int top=-1;
char stack[10];
void push(char c)
{
        stack[++top]=c;
}
char pop()
{
        return stack[top--];
}
int priority(char ch)
{
        if(ch=='*'||ch=='/')
                return 2;
        else if(ch=='+'||ch=='-')
                return 1;
        else
                return 0;
}
void main()
{
        char postfix[10],infix[10];
        int i=0,j=0,k=0;
        printf("enter expression\n");
        scanf("%s",infix);
        char ch=infix[0];
   while(ch!='\0')
        {
                if(ch=='(')
                        push(ch);
                else if(isdigit(ch)||isalpha(ch))
                {
                        postfix[j]=ch;
                        j++;
                }
                else if(ch==')')
                {
                        char x;
                        x=pop();
                        while(stack[top]!='(')
                        {
                                postfix[j]=x;
                                j++;
                        }x=pop();
                        push(x);
                }
                else if(ch=='+'||ch=='-'||ch=='*'||ch=='/')
                {
                        if(priority(ch)<=priority(stack[top]))
                        {
                                while(priority(ch)<=priority(stack[top]))
                                {
                                        postfix[j]=pop();
                                        j++;
                                }
                           push(ch);
                        }
                        else
                        {
                                push(ch);
                        }
                }
                i++;
                ch=infix[i];
        }
        if(top!=-1)
        {
                while(top!=-1)
                {
                        postfix[j]=pop();
                        j++;
                }
        }
        printf("%s",postfix);
}
