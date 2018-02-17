#include<iostream>
using namespace std;
struct node{
  int data;
  struct node *link;
};

struct node *pushNode(struct node *start,int n)
{
  struct node *p,*temp=(struct node *)malloc(sizeof(struct node));
  temp->data=n;
  temp->link=NULL;

  if(!start)
  return temp;

  temp->link=start;
  start=temp;

  return start;
}

struct node *pop(struct node *start)
{
  struct node *temp=start;
  cout<<temp->data<<endl;
  start=start->link;
  free(temp);
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
  int choice,n;
  struct node *start=NULL;
  while(1)
  {
    cout<<"1.Push"<<endl;
    cout<<"2.Pop"<<endl;
    cout<<"3.Display"<<endl;
    cout<<"4.Exit"<<endl;
    cin>>choice;
    switch(choice){
      case 1:
      cin>>n;
      start=pushNode(start,n);
      break;

      case 2:
      start=pop(start);
      break;

      case 3:
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
