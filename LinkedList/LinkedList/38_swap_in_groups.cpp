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

struct node *block_swap(struct node *start,int n)
{
  struct node *cur=start,*prev=NULL,*next=NULL;
  int cnt=0;

  while(cur && cnt<n)
  {
    next=cur->link;
    cur->link=prev;
    prev=cur;
    cur=next;
    cnt++;
  }
  if(next)
  start->link=block_swap(next,n);

  return prev;
}

int main ()
{
  int choice,n;
  struct node *newHead,*start=NULL;

  for(int i=1;i<=7;i++)
  start=insertNode(start,i);
  Display(start);
  cin>>n;

  start=block_swap(start,n);
  Display(start);


  return 0;
}
