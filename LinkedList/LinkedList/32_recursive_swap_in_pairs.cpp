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
  struct node *temp=NULL;
  if(!start || !start->link)
  return start;
  else
  {
    temp=start->link;
    start->link=temp->link;
    temp->link=start;
    start=temp;

    start->link->link=swapPairs(start->link->link);
  }
  return start;
}

int main ()
{
  int choice;
  struct node *start=NULL;

  for(int i=1;i<=6;i++)
  start=insertNode(start,i);
  Display(start);
  start=swapPairs(start);
  Display(start);
  return 0;
}
