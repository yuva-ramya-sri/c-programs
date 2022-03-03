#include<stdio.h>
#include<stdlib.h>
struct node{
        int data;
        struct node *next;
}*newnode,*temp;
void create( );
void display( );
void insert_beg( );
void insert_end( );
void insert_pos( );
void delete_beg( );
void delete_pos( );
void delete_end( );
void count_nodes( );
struct node *head=NULL;
struct node *tail=NULL;
void main( )
{
        int ch;
        create( );
        printf("Press 1 to display the created linked list\nPress 2 to insert a element in the beginning\nPress3 to insert a element in the ending\nPress 4 to insert a element in a particular position\nPress 5 to delelte atbeginning\nPress 6 to delete at end\nPress 7 to delete at a particular position\n");
        scanf("%d",&ch);
        if(ch==1)
        {
              display( );
        }

        else if(ch==2)
        {
                insert_beg( );
 }
        else if(ch==3)
        {
                insert_end( );
        }
        else if(ch==4){
                insert_pos( );
        }
        else if(ch==5){
                delete_beg( );
        }
        else if(ch==6){
                delete_end( );
        }
        else if(ch==7){
                delete_pos( );
        }
        else
        {
                count_nodes( );
        }

}
void create( )
{
        int val;
        char ch;
        do{
                newnode=(struct node *)malloc(sizeof(struct node));
                printf("enter the value: ");
                scanf("%d",&val);
                newnode->data=val;
                newnode->next=NULL;
                if(head==NULL)
                {
                        head=newnode;
                        tail=newnode;
                }
                else
                {
                        tail->next=newnode;
                        tail=newnode;

                }
                printf("Do you want to insert another element? if yes press y else n: ");
                fflush(stdin);
                scanf(" %c",&ch);
        }while(ch=='y');
}
void display( )
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
        int val;
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("enter value\n");
        scanf("%d",&val);
        newnode->data=val;
        newnode->next=head;
        head=newnode;
        printf("the new list is: ");
        display( );
}
void insert_end()
{
        int val;
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter a value: ");
        scanf("%d",&val);
        newnode->data=val;
        newnode->next=NULL;
        tail->next=newnode;
        tail=newnode;
        printf("the new list is: ");
        display( );
}
void insert_pos( )
{
        int pos,value,i;
        temp=head;
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("enter value: ");
        scanf("%d",&value);
        printf("enter position: ");
        scanf("%d",&pos);
        for(i=0;i<pos-1;i++)
        {
                temp=temp->next;
        }
        newnode->data=value;
        newnode->next=temp->next;
 temp->next=newnode;
        printf("the new list is: ");
        display( );
}
