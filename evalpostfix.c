
#include<stdio.h>
#include<string.h>
#include<ctype.h>
char stack[10];
int top=-1;
void push(char c){
    stack[++top]=c;
}
char pop()
{
    return(stack[top--]);
}
int operation(int op1,int op2,char c){
    switch(c){
        case '*':return(op1*op2);
        break;
        case '+':return(op1+op2);
        break;
        case '-':return(op1-op2);
        break;
        case '/':return(op1/op2);
        break;
    }    
}
void main()
{
    char postfix[10];
    printf("enter postfix expression: ");
    scanf("%s",postfix);
    int i=0;
    while(postfix[i]!='\0'){
        char c=postfix[i];
        if(isdigit(c)){
            push(c-'0');
        }
        else{
            int op1,op2;
            op1=pop();
            op2=pop();
            int result=operation(op1,op2,c);
            push(result);
        }
        i++;
    }
    printf("the result is:%d",stack[top]);
}
