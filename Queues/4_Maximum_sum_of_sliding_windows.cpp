#include<iostream>
using namespace std;
struct node{
  int data;
  struct node *link;
};

struct node *front_enqueue(struct node *start,int n)
{
  struct node *temp=(struct node *)malloc(sizeof(struct node)),*p=start;
  temp->data=n;
  temp->link=NULL;

  if(!start)
  return temp;

  temp->link=start;
  start=temp;

  return start;
}

struct node *front_dqueue(struct node *start)
{
  if(!start)
  return start;

  struct node *temp=start;
  start=start->link;
  free(start);
  return start;
}

struct node *back_enqueue(struct node *start,int n)
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
struct node *back_dqueue(struct node *start)
{
  if(!start)
  return start;

  struct node *p=start;
  while(p->link->link)
  {
    if(p)
    p=p->link;
    
  }

   p->link=NULL;
  return start;
}
void display(struct node *start)
{
  struct node *p=start;
  while(p)
  {
    cout<<p->data;
    p=p->link;
  }
  return;
}


int main()
{
  struct node *start=NULL;
  int choice,n;
  while(1)
  {
    cout<<endl<<"1.Enqueue in Front"<<endl;
    cout<<"2.Dequeue in Front"<<endl;
    cout<<"3.Enqueue in Back"<<endl;
    cout<<"4.Dequeue in Back"<<endl;
    cout<<"5.Display"<<endl;
    cout<<"6.Exit"<<endl;
    cin>>choice;

    switch (choice) {
      case 1:
      cin>>n;
      start = front_enqueue(start,n);
      display(start );
      break;

      case 2:
      start = front_dqueue(start);
      display(start);
      break;

      case 3:
      cin>>n;
      start = back_enqueue(start,n);
      display(start );
      break;

      case 4:
      start = back_dqueue(start);
      display(start);
      break;

      case 5:
      display(start);
      break;

      case 6:
      exit(1);
      break;

      default:
      cout<<"Wrong choice"<<endl;
    }

  }
  return 0;
}
