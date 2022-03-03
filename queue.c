#include<stdio.h>
int que[50];
int front=0,rear=0;
void insertq(int ele)
{
        if(rear==50)
        {
                printf("QUEUE IS FULL");
                return;
        }
        else
        {
                que[rear]=ele;
                rear++;
        }
}
int deleteq()
{
        if(rear==front)
        {
                printf("queue is empty");
                return 0;
        }
        else
        {
                int d = que[front];
                front++;
                return d;
        }
        }
void display()
{
        int i;
        for(i=front;i<rear;i++)
        {
                printf("%d ",que[i]);
        }
}
void main()
{
        printf("enter 1 to display enter 2 to insert and enter 3 to delete an element\n");
        int ch;
        insertq(4);
        insertq(6);
        scanf("%d",&ch);
        if(ch==1)
        {
                display();
        }
        else if(ch==2)
        {
                int dat;
                printf("enter element: \n");
                scanf("%d",&dat);
                insertq(dat);
                display();
        }
        else if(ch==3)
        {
                printf("the deleted element is: %d\n",deleteq());
                display();
        }
}
