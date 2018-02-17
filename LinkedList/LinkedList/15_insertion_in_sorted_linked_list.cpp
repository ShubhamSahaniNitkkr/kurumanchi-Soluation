#include<iostream>
using namespace std;
struct node{
  int data;
  struct node *link;
};

struct node *insertNode(struct node *start,int n)
{
  struct node *q,*p,*temp=(struct node *)malloc(sizeof(struct node));
    temp->data=n;
    temp->link=NULL;

    if(!start)
    return temp;

     if(n < start->data)
    {
      temp->link=start;
      start=temp;
      return start;
    }

    p=start;
    while(p!=NULL && p->data < n)
    {
      q=p;
      p=p->link;
    }

    temp->link=p;
    q->link=temp;

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
  return;
}


int main ()
{
  int choice,n,pos;
  struct node *start=NULL;
  while(1)
  {
    cout<<endl;
    cout<<"1.Insert"<<endl;
    cout<<"2.Display"<<endl;
    cout<<"3.Exit"<<endl;
    cin>>choice;
    switch(choice){
      case 1:
      cin>>n;
      start=insertNode(start,n);
      Display(start);
      break;

      case 2:
      Display(start);
      break;

      case 3:
      exit(1);
      break;

      default:
      cout<<"Wrong Choice !"<<endl;
    }
  }
  return 0;
}
