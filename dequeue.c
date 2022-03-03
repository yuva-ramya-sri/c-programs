#include<stdio.h>
#include<stdlib.h>
int de[5];
int n=5;
int c=0;
int front=0,rear=0;
void insert_front(int ele)
{
 if(front<=0 && rear!=0)
 {
 front=n-1;
 de[front]=ele;
 }
 else if(front>0)
 {
 front=front-1;
 de[front]=ele;
 }
 else if(front==0 && rear==0)
 {
 de[front]=ele;
 front--;
 }
 c++;
}
void insert_rear(int ele)
{
 if(c!=n && rear!=n-1)
 {
 rear=rear+1;
 de[rear]=ele;
 c++;
 }
 if(c!=n && rear==n-1)
 {
 rear=0;
 de[rear]=ele;
 c++;
 }
 if(c!=n && front==0 && rear==0)
 {
 de[rear]=ele;
 rear=rear+1;
 c++;
 }
}
void delete_front()
{
 if(c>0)
 {
 if(front==n-1)
 {
 printf("deleted:%d",de[front]);
 front=0;
 }
 else
 {
 printf("delted: %d\n",de[front]);
 front=front+1;
 }
 c--;
 }
}
void delete_rear()
{
 if(c>0)
 {
 if(rear==0)
 {
 printf("deleted: %d\n",de[rear]);
 rear=n-1;
 }
 else
 {
 printf("deleted:%d\n",de[rear]);
 rear=rear-1;
 }
 c--;
 }
}
void display()
{
 int i=front;
 while(i!=rear+1)
 {
 printf("%d ",de[i]);
 i=(i+1)%n;
 }
}
void main()
{
 int n,a;
 printf("==================menu=================");
 printf("enter 1 to insert at front\nenter 2 to insert at rear\nenter 3 to delete at front\nenter 4 to delete at rear\n");
 scanf("%d",&n);
 insert_front(6);
 insert_rear(8);
 insert_front(10);
 if(n==1) 
 {
 printf("enter element: ");
 scanf("%d",&a);
 insert_front(a);
 }
 else if(n==2)
 {
 printf("enter element: ");
 scanf("%d",&a);
 insert_rear(a);
 }
 else if(n==3)
 {
 delete_front();
 }
 else
 {
 delete_rear();
 }
 display();
}
