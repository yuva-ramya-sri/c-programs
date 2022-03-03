#include<stdio.h>
#include<stdlib.h>
struct bst
{
 int data;
 struct bst *left,*right;
};
typedef struct bst node;
node *insert(node *p,int x)
{
 node *new;
 if(p==NULL)
 {
 new=(node *)malloc(sizeof(node));
 new->data=x;
 new->left=new->right=NULL;
 p=new;
 }
 else if(x<=p->data)
 {
 p->left=insert(p->left,x);
 }
 else if(x>p->data)
 {
 p->right=insert(p->right,x);
 }
 return p;
}
void inorder(node *p)
{
 if(p!=NULL)
 {
 inorder(p->left);
 printf("%d\t",p->data);
 inorder(p->right);
 }
}
void preorder(node *p)
{
 if(p!=NULL)
 {
 printf("%d\t",p->data);
 preorder(p->left);
 preorder(p->right);
 }
}
void postorder(node *p)
{
 if(p!=NULL)
 {
 postorder(p->left);
 postorder(p->right);
 printf("%d\t",p->data);
 }
}
node *findmin(node *p)
{
 if(p!=NULL)
 {
 while(p->left!=NULL)
 {
 p=p->left;
 }
 return p;
 }
}
node *findmax(node *p)
{
 if(p!=NULL)
 {
 while(p->right!=NULL)
 {
 p=p->right;
 }
 return p;
 }
}
node *search(node *p,int x)
{
 if(p==NULL)
 return p;
 else if(x<p->data)
 {
 return(search(p->left,x));
 }
 else if(x>p->data)
 {
 return(search(p->right,x));
 }
 else
 {
 return p;
 }
}
node *delete(node *p,int x)
{
 if(p==NULL)
 return p;
 else if(x<p->data)
 {
 p->left=delete(p->left,x);
 }
 else if(x>p->data)
 {
 p->right=delete(p->right,x);
 }
 else if(p->left!=NULL && p->right!=NULL)
 {
 x=p->data=findmin(p->right)->data;
 p->right=delete(p->right,x);
 }
 else
 {
 node *temp=p;
 if(p->left==NULL)
 {
 p=p->right;
 }
 else
 {
 p=p->left;
 }
 free(temp);
 }
 return p;
}
void main()
{
 node *root=NULL,*temp;
 int x,ch;
 printf("1:insert\n 2:inorder\n 3:preorder\n 4:postorder\n 5:findmin\n 6:findmax\n 7:search\n 8:delete\n 9:exit\n");
 while(1)
 {
 printf("enter choice");
 scanf("%d",&ch);
 switch(ch)
 {
 case 1:printf("enter data");
 scanf("%d",&x);
 root=insert(root,x);
 break;
 case 2:printf("inorder:");
 inorder(root);
 break;
 case 3:printf("preorder");
 preorder(root);
 break;
 case 4:printf("postorder:");
 postorder(root);
 break;
 case 5:temp=findmin(root);
 if(temp==NULL)
 {
 printf("no list");
 }
 else
 {
 printf("min=%d",temp->data);
 }
 break;
 case 6:temp=findmax(root);
 if(temp==NULL)
 {
 printf("no list");
 }
 else
 {
 printf("max=%d",temp->data);
 }
 break;
 case 7:printf("enter ele to search:");
 scanf("%d",&x);
 temp=search(root,x);
 if(temp==NULL)
 {
 printf("the ele %d is not found",x);
 }
 else
 {
 printf("the ele is found %d",x);
 }
 break;
 case 8:printf("enter ele to delte:");
 scanf("%d",&x);
 root=delete(root,x);
 break;
 case 9:exit(0);
 break;
 }
 }
}
