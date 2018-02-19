#include<iostream>
using namespace std;

struct node{
  int data;
  struct node *link;
};

struct node *enqueue(struct node * start,int n)
{
  struct node *temp=(struct node *)malloc(sizeof(struct node)),*p=start;
  temp->data=n;
  temp->link=NULL;

  if(!start)
  return temp;

  while(p->link!=NULL)
   p=p->link;
    p->link=temp;
  return start;
}

struct node *dqueue(struct node * start)
{
  if(!start)
  return start;
  struct node *temp=start;
  start=start->link;
  free(start);
  return start;
}

void display(struct node * start)
{
  if(!start)
  return ;

  struct node *p=start;
  while(p)
  {
    cout<<p->data<<"->";
    p=p->link;
  }
  cout<<endl;
}


int main()
{
  struct node *start=NULL;
  int choice,n;
  while(1)
  {
    cout<<endl<<"1.Enqueue"<<endl;
    cout<<"2.Deque"<<endl;
    cout<<"3.Display"<<endl;
    cout<<"4.Exit"<<endl;
    cin>>choice;

    switch (choice) {
      case 1:
      cin>>n;
      start=enqueue(start,n);
      display(start);
      break;

      case 2:
      start=dqueue(start);
      display(start);
      break;

      case 3:
      display(start);
      break;

      case 4:
      exit(1);
      break;

      default:
      cout<<"Wrong choice"<<endl;
    }

  }
  return 0;
}
