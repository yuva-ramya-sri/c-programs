#include<stdio.h>
#include<stdlib.h>
struct node
{
        int data;
        struct node *next;
}*newnode,*temp;
struct node *head=NULL;
struct node *tail=NULL;
void create();
void display();
void insert_beg();
void insert_end();
void insert_pos();
void delete_beg();
void delete_end();
void delete_pos();
void main()
{
        create();
        printf("Press 1 to display the cll\n Press 2 to insert at beginning\n3to insert at end\n4 to insert at position\n5 to delete at beginning\n 6 to delete at end\n7 to delete at position\n");
        int ch;
        scanf("%d",&ch);
        if(ch==1)
                display();
        else if (ch==2)
                insert_beg();
        else if(ch==3)
           insert_end();
        else if(ch==4)
                insert_pos();
        else if(ch==5)
                delete_beg();
        else if(ch==6)
                delete_end();
        else
                delete_pos();

}
void create()
{
        int value;
        char ch;
        do{
        newnode=(struct node *)malloc(sizeof(struct node));
        printf("enter value: ");
        scanf("%d",&value);
        newnode->data=value;
        newnode->next=NULL;
        if(head==NULL)
        {
                head=newnode;
                tail=newnode;
                newnode->next=head;
        }
        else
        {
           tail->next=newnode;
                tail=newnode;
                tail->next=head;
        }
        printf("do you want to continue?: ");
        fflush(stdin);
        scanf(" %c",&ch);
        }while(ch=='y');
}
void display()
{
        temp=head;
        while(temp->next!=head)
        {
                printf("%d ",temp->data);
                temp=temp->next;
        }
        printf("%d ",temp->data);
}
void insert_beg()
{
        int value;
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("enter the value: ");
        scanf("%d",&value);
        newnode->data=value;
        newnode->next=head;
        tail->next=newnode;
        head=newnode; display();
}
void insert_end()
{
        int value;
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("enter value: ");
        scanf("%d",&value);
        newnode->data=value;
        newnode->next=head;
        tail->next=newnode;
        tail=newnode;
        display();
}
void insert_pos()
{
        int value,pos;
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("enter position and value: ");
        scanf("%d",&pos);
        scanf("%d",&value);
        newnode->data=value;
        temp=head;
        for(int i=0;i<pos-1;i++)
        {
                temp=temp->next;
        }
        newnode->next=temp->next;
        temp->next=newnode;
  display();
}
void delete_beg()
{
        temp=head;
        head=head->next;
        temp->next=NULL;
        tail->next=head;
        display();
}
void delete_end()
{
        temp=head;
        while(temp->next!=tail)
        {
                temp=temp->next;
        }
        temp->next=NULL;
        tail=temp;
        tail->next=head;
