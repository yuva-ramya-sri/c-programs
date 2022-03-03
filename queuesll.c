#include<stdio.h>
#include<stdlib.h>
struct node{
        int data;
        struct node *next;
}*newnode,*temp;
struct node *rear=NULL;
struct node *front=NULL;
void insertq(int ele)
{
        newnode=(struct node *)malloc(sizeof(struct node));
        newnode->data=ele;
        if(front==rear&&front==NULL)
        {
                newnode->next=NULL;
                front=newnode;
                rear=newnode;
        }
        else
        {
                rear->next=newnode;
                newnode->next=NULL;
                rear=newnode;
        }
}
int deleteq()
{
        if(front==rear && front==NULL)
        {
{
                printf("queue is full");
                return 0;
        }
        else
        {
                temp=front;
                int d;
                d=temp->data;
                front=front->next;
                temp->next=NULL;
                return d;
        }
}
void display()
{
        temp=front;
        while(temp!=NULL)
        {
                printf("%d ",temp->data);
          temp=temp->next;
        }
}
void main()
{
        printf("enter 1 to display entr 2 to insert enter 3 to delete\n");
        int ch;
        scanf("%d",&ch);
        insertq(9);
        insertq(10);
        if(ch==1)
        {
                display();
        }
        else if(ch==2)
        {
                printf("enter element\n");
                int d;
                scanf("%d",&d);
                insertq(d);
                display();
        }
        else
        {
                printf("the deleted element is:%d\n",deleteq());
                display();
        }
}
