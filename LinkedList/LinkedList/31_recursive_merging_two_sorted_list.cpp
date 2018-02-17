#include<iostream>
using namespace std;
struct node{
  int data;
  struct node *link;
};

struct node *insertNode(struct node *start,int n)
{
  struct node *p,*temp=(struct node *)malloc(sizeof(struct node));
  temp->data=n;
  temp->link=NULL;

  if(!start)
  return temp;

  p=start;
  while(p->link!=NULL)
   p=p->link;
    p->link=temp;

  return start;
}


void Display(struct node *start)
{
  if(!start)
  {
    cout<<"List is Empty"<<endl;
    return;
  }
  struct node *p=start;
  while(p!=NULL)
  {
    cout<<p->data<<'\t';
    p=p->link;
  }
  cout<<endl;
  return;
}


struct node *merge(struct node *p,struct node *q)
{
  struct node *temp,*newstart;
  if(!q)
  return p;

  if(!p)
  return q;

   if(p && q)
   {
     if(p->data<=q->data)
     {
       newstart=p;
       p=newstart->link;
     }
     else
     {
       newstart=q;
       q=newstart->link;
     }
   }


  temp=newstart;

  while(p && q)
  {
    if(p->data<=q->data)
    {
      newstart->link=p;
      newstart=p;
      p=newstart->link;

    }
    else
    {
      newstart->link=q;
      newstart=q;
      q=newstart->link;
    }
  }
  if(!q)newstart->link=p;

  if(!p)newstart->link=q;

  return temp;

}

int main ()
{
  int choice;
  struct node *start=NULL,*start1=NULL;

  for(int i=1;i<=5;i++)
  start=insertNode(start,i);

  for(int i=4;i<=25;i+=4)
  start1=insertNode(start1,i);

  Display(start);
  Display(start1);

  start=merge(start,start1);
  Display(start);

  return 0;
}
