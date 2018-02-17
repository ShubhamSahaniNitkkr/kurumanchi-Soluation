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

struct node *reverse(struct node *start)
{
  struct node *p=NULL,*q=NULL;

  if(!start)
  return start;

  p=start;
  q=p->link;

  if(!q)
  return p;

  q=reverse(q);

  p->link->link=p;
  p->link=NULL;

  return q;
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
  return;
}


int main ()
{
  int choice;
  struct node *start=NULL;
  while(1)
  {
    cout<<endl;
    cout<<"1.Insert"<<endl;
    cout<<"2.Reverse"<<endl;
    cout<<"4.Exit"<<endl;
    cin>>choice;
    switch(choice){
      case 1:
      for(int i=4;i<40;i+=5)
      start=insertNode(start,i);
      Display(start);
      break;

      case 2:
      start=reverse(start);
      Display(start);
      break;

      case 4:
      exit(1);
      break;

      default:
      cout<<"Wrong Choice !"<<endl;
    }
  }
  return 0;
}
