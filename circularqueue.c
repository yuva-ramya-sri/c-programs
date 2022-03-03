#include<stdio.h>
int cir[10];
int front=0,rear=0,count=0;
void insertq(int ele)
{
        if(count==10)
        {
                printf("queue is full");
        }
        else
        {
                cir[rear]=ele;
                rear=(rear+1)%10;
                count=count+1;
        }
}
int deleteq()
{
        if(front==rear)
        {
                printf("queue is empty");
                return 0;
        }
        else
        {
                int d;
                d=cir[front];
                front=(front+1)%10;
                return d;
                        }
}
void display()
{
        for(int i=front;i<=rear;i++)
        {
                printf("%d ",cir[i]);
        }
}
void main()
{
        int ch;
        char c='y';
        insertq(6);
        do{
        printf("enter 1 to display enter 2 to insert enter 3 to delete \n");
        scanf("%d",&ch);
        if(ch==1)
        {
                display();
        }
        else if(ch==2)
        {
                int d;
                printf("enter the lelemnt to insert: ");
                scanf("%d",&d);
                insertq(d);
                display();
        }
        else if(ch==3)
        {
                printf("the deleted element is%d\n",deleteq());
                display();
        }
        printf("continue?");
        scanf(" %c",&c);
        }while(c=='y');
}
