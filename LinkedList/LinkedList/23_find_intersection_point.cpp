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

void merge_point(struct node *start,struct node *start1)
{
  struct node *p=start,*p1=start1;
  int count=0,count1=0,pass=0;

  while(p!=NULL)
  {
    p=p->link;
    count++;
  }

  while(p1!=NULL)
  {
    p1=p1->link;
    count1++;
  }

  if(count>count1)
  {
    pass=count-count1;
    p=start;
    p1=start1;
  }
  else
  {
    pass=count1-count;
    p=start1;
    p1=start;
  }

  for(int i=0;i<pass;i++)
   p=p->link;

   while(p!=p1)
   {
     p=p->link;
     p1=p1->link;
   }
   cout<<p->data;

  return;
}



int main ()
{
  int choice;
  struct node *start=NULL,*start1=NULL,*start2=NULL,*p=NULL,*p1=NULL;

  for(int i=1;i<5;i++)
  start=insertNode(start,i);

  for(int i=5;i<=20;i+=5)
  start1=insertNode(start1,i);

  for(int i=6;i<=10;i++)
  start2=insertNode(start2,i);

  p=start;
  p1=start1;

  while(p->link!=NULL)
   p=p->link;
  p->link=start2;

  while(p1->link!=NULL)
   p1=p1->link;
  p1->link=start2;

  Display(start1);
  Display(start);


  merge_point(start,start1);

  return 0;
}
