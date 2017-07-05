#include<stdio.h>
#include<stdlib.h>
struct node
{
 int element;
 struct node *left;
 struct node *right;
}*q,*par,*root;
int create();
int insert();
int search();
int preorder();
int inorder();
int postorder();
int main()
{
 int z,ch,num;
 do
 {
  printf("\n1.create tree");
  printf("\n2.Insert");
  printf("\n3.Search");
  printf("\n4.preorder");
  printf("\n5.Inorder");
  printf("\n6.postorder");
  printf("\nEnter ur choice:");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:
    create();
   break;
   case 2:
    insert();
   break;
   case 3:
    search();
   break;
   case 4:
    preorder(root);
   break;
   case 5:
    inorder(root);
   break;
   case 6:
    postorder(root);
   break;
   default:
    printf("\nEnter the correct choice");
   break;
  }
  printf("\npress 1 to contn");
  scanf("%d",&z);
 }while(z>0);
}

int create()
{
 int num;
 root=malloc(sizeof(struct node));
 printf("\nEnter the element");
 scanf("%d",&num);
 root->element=num;
 root->left=NULL;
 root->right=NULL;
 printf("\nRoot node is created");
}

int insert()
{
 struct node *par,*q,*t;
 int num;
 scanf("%d",&num);
 q=par=root;
 while(q!=NULL)
 {
  if(num>q->element)
  {
   par=q;
   q=q->right;
  }
  else if(num<q->element)
  {
   par=q;
   q=q->left;
  }
  else
  {
   printf("\nElement is exists");
  }
 }
 t=malloc(sizeof(struct node));
 t->element=num;
 t->left=NULL;
 t->right=NULL;
 if(num>par->element)
 par->right=t;
 else
 par->left=t;
 printf("Element inserted %d",t->element);
}

int search()
{
 int num,flag=0;
 printf("\nEnter the element:");
 scanf("%d",&num);
 q=par=root;
 while(q!=NULL)
 {
  if(num>q->element)
  {
   par=q;
   q=q->right;
  }
  else if(num<q->element)
  {
   par=q;
   q=q->left;
  }
  else
  {
   flag=1;
   printf("\nElement is found");
   break;
  }
 }
 if(q==NULL)
 printf("\nElement is not found");
}

int preorder(struct node *q)
{
 if(q!=NULL)
 {
  printf("%d\t",q->element);
  preorder(q->left);
  preorder(q->right);
 }
}

int inorder(struct node *q)
{
 if(q!=NULL)
 {
  inorder(q->left);
  printf("%d\t",q->element);
  inorder(q->right);
 }
}

int postorder(struct node *q)
{
 if(q!=NULL)
 {
  postorder(q->left);
  postorder(q->right);
  printf("%d\t",q->element);
 }
}
