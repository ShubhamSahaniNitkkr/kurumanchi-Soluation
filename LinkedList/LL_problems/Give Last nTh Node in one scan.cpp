#include<iostream>
using namespace std;

struct node {
  int data;
  struct node *link;
};

void display(struct node *start)
{
  struct node *p=start;
  if(!p)
  return;
  while(p!=NULL)
  {
    cout<<p->data<<" ";
    p=p->link;
  }
  cout<<endl;
  return;
}

void lastNthNode(struct node *start,int pos)
{
  struct node *p1,*p2=start;
  p1=NULL;
  for(int i=1;i<pos;i++)
   if(p2)
   p2=p2->link;

   while(p2)
   {
     if(p1==NULL)
      p1=start;
     else
      p1=p1->link;

     p2=p2->link;
   }

  if(p1)
  cout<<p1->data<<endl;
  else
  cout<<"Position Does not exist !"<<endl;

  return;
}

struct node *createnode(struct node *start,int data)
{
  struct node *p,*temp=(struct node *)malloc(sizeof(struct node));
  temp->data=data;
  temp->link=NULL;

  if(!start)
  return temp;

  p=start;
  while(p->link!=NULL)
   p=p->link;

   p->link=temp;
  return start;
}

int main()
{
  struct node *start=NULL;

  for(int i = 11;i <= 22;i++)
    start=createnode(start,i);

  display(start);

  int k;
  while(1)
  {
    cin>>k;
    if(k==-1){exit(1);}
    lastNthNode(start,k);
  }

  return 0;
}
