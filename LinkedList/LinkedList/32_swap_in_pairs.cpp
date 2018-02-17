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


struct node *swapPairs(struct node *start)
{
  struct node *p,*q,*temp,*newstart;
  p=start;
  newstart=p->link;

  while(1)
  {
    q=p->link;
    temp=q->link;

    q->link=p;
    p->link=temp;

    if(!temp || !temp->link)
    {
      p->link=temp;
      break;
    }
    p->link=temp->link;
    p=temp;

  }
  return newstart;
}

int main ()
{
  int choice;
  struct node *start=NULL;

  for(int i=1;i<=5;i++)
  start=insertNode(start,i);
  Display(start);
  start=swapPairs(start);
  Display(start);
  return 0;
}
