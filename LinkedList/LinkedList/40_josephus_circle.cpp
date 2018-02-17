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
  temp->link=temp;

  if(!start)
  return temp;

  p=start;
  do{
    p=p->link;
  }while(p->link!=start);
  temp->link=p->link;
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
  do{
    cout<<p->data<<"->";
    p=p->link;
  }while(p!=start);

  cout<<endl;
  return;
}


int main ()
{
  int choice;
  struct node *start=NULL,*p;

  int n,m;
  cin>>n>>m;

  for(int i=1;i<=n;i++)
  start=insertNode(start,i);

  p=start;
  for(int i=1;i<n;i++)//should run when at most 1 person still reside
  {
    for(int j=1;j<m;j++)//stops before 1step of location need to be removed
      p=p->link;
    p->link=p->link->link;
  }
  cout<<p->data;

  return 0;
}
