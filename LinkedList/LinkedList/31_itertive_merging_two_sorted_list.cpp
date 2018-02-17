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


struct node *merge(struct node *start,struct node *start1)
{
  struct node *p=start,*p1=start1;
  while(p->link && p1->link)
  {
    if(p1->data < p->data)
    {
      struct node *temp=(struct node *)malloc(sizeof(struct node));
      temp->data=p->data;
      temp->link=p1->link;
      p1->link=temp;
    }
    p1=p1->link;
    p=p->link;
  }
  return start;
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

  cout<<endl;

  start=merge(start,start1);
  Display(start);

  return 0;
}
