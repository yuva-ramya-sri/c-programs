#include<stdio.h>
void push(int stack[],int *top)
{
        int element,size=10;
        if(*top==size-1)
        {
                printf("stack overflow");
        }
        else
        {
                printf("enter element:");
                scanf("%d",&element);
                (*top)++;
                stack[*top]=element;
        }
}
void display(int stack[],int top)
{
        if(top!=-1)
        {
                for(int i=0;i<=top;i++)
                {
                        printf("%d\n",stack[i]);
                }
        }
        else
        {
                printf("no element present");
        }
  }
void pop(int stack[],int *top)
{
        int ele;
        if(*top==-1)
        {
                printf("stack overflow\n");
        }
        else
        {
                ele=stack[*top];
                printf("removed element is: %d\n",ele);
                (*top)--;
        }
}


void main()
{
        int stack[10],choice,top=-1;
        printf("enter 1 to insert an element in stack\n");
        scanf("%d",&choice);
        stack[0]=5;
        top++;
        stack[1]=8;
        top++;
        if(choice==1)
        {
                push(stack,&top);
          }
        if(choice==2)
        {
                pop(stack,&top);
        }
        display(stack,top);
}
