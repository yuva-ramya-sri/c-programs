#include<stdio.h>
#include<stdlib.h>
struct node
{
 int data;
 struct node *next;
 struct node *prev;
}*newnode,*temp;
struct node *head=NULL;
struct node *tail=NULL;
void create()
{
 int value;
 char ch;
 do
 {
 newnode=(struct node*)malloc(sizeof(struct node));
 printf("enter value: ");
 scanf("%d",&value);
 newnode->data=value;
 newnode->next=NULL;
 newnode->prev=NULL;
 if(head==NULL)
 {
 head=newnode;
 tail=newnode;
 }
 else
 {
 newnode->prev=tail;
 tail->next=newnode;
 tail=newnode;
 }
 printf("wanna continue: ");
 fflush(stdin);
 scanf(" %c",&ch);
 }while(ch=='y');
}
void display()
{
 temp=head;
 while(temp!=NULL)
 {
 printf("%d ",temp->data);
 temp=temp->next;
 }
}
void insert_beg()
{
 int value;
 newnode=(struct node*)malloc(sizeof(struct node));
 printf("enter value: ");
 scanf("%d",&value);
 newnode->data=value;
 newnode->prev=NULL;
 newnode->next=head;
 head->prev=newnode;
 head=newnode;
 display();
}
void insert_end()
{
 int value;
 newnode=(struct node *)malloc(sizeof(struct node));
 printf("enter value: ");
 scanf("%d",&value);
 newnode->data=value;
 newnode->next=NULL;
 newnode->prev=tail;
 tail->next=newnode;
 tail=newnode;
 display();
}
void insert_pos(){
int value,pos,i;
newnode=(struct node*)malloc(sizeof(struct node));
printf("enter value & pos: ");
scanf("%d",&value);
scanf("%d",&pos);
temp=head;
for(i=0;i<pos-1;i++)
{
 temp=temp->next;
}
newnode->data=value;
newnode->prev=temp;
newnode->next=temp->next;
 temp->next->prev=newnode;
temp->next=newnode;
display();
}
void delete_beg()
{
 temp=head;
 head=head->next;
 temp->next=NULL;
 head->prev=NULL;
 display();
}
void delete_end()
{
 temp=tail;
 tail=tail->prev;
 temp->prev=NULL;
 tail->next=NULL;
 display();
}
void delete_pos()
{
 int pos,i;
 printf("enter position to delete: ");
 scanf("%d",&pos);
 temp=head;
 for(i=0;i<pos-2;i++)
 {
 temp=temp->next; }
 temp->next->prev=NULL;
 temp->next=temp->next->next;
 temp->next->prev=temp;
 display();
}


void main()
{
 int ch;
 create();
 printf("1 display\n2 insert beg\n3 insert end\n4 insert pos\n5 delete beg\n6 delete end\n7 delete pos\n");
 scanf("%d",&ch);
 if(ch==1)
 display();
 if(ch==2)
 insert_beg();
 if(ch==3)
 insert_end();
 if(ch==4)
 insert_pos();
 if(ch==5)
 delete_beg();
 if(ch==6)
 delete_end();
 if(ch==7)
 delete_pos();
}
