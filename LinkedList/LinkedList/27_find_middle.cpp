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

void find_middle(struct node *start)
{
  struct node *p,*q;
  p=q=start;
  int i=0;
  while(p->link!=NULL)
  {
    if(i==0)
    {
      p=p->link;//doubling speed
      i=1;
    }
    if(i==1)
    {
      p=p->link;
      q=q->link;
      i=0;
    }
  }
  cout<<q->data<<endl;
  return;
}

int main ()
{
  int choice;
  struct node *start=NULL;

  for(int i=1;i<=5;i++)
  start=insertNode(start,i);
  Display(start);
  find_middle(start);

  return 0;
}
