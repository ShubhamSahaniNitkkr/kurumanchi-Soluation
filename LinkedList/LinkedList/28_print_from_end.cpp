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


void display_From_End(struct node *start)
{
  if(!start)
  return;

  display_From_End(start->link);
  cout<<start->data<<" ";

}



int main ()
{
  int choice;
  struct node *start=NULL;

  for(int i=1;i<=5;i++)
  start=insertNode(start,i);
  display_From_End(start);

  return 0;
}
