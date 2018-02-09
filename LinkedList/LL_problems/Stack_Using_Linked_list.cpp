#include<iostream>
using namespace std;

struct node {
  int data;
  struct node *link;
};


void display(struct node *start)
{
  struct node *p=start;
  while(p!=NULL)
  {
    cout<<p->data<<" ";
    p=p->link;
  }
  cout<<endl;
}

struct node *push(struct node *start,int data)
{
  struct node *temp=(struct node *)malloc(sizeof(struct node));
  temp->data=data;
  temp->link=NULL;
  if(!start)
  return temp;

  temp->link=start;
  start=temp;
  return start;
}

struct node *pop(struct node *start)
{
  if(start)
  {
    struct node *temp=start;
    cout<<temp->data<<" ";
    start= start->link;
    free(temp);
    return start;
  }
  else
  cout<<"Empty List"<<endl;
  return start;

}

int main()
{
  struct node *start=NULL;
  int k,n;
  while(1)
  {
    cout<<"1.Push"<<endl<<"2.Pop"<<endl;
    cin>>k;
    if(k==0){exit(1);}
    if(k==1)
    {
      cin>>n;
      start=push(start,n);
      display(start);
    }
    else if(k==2)
    {
       start=pop(start);
       cout<<endl;
      display(start);
    }
  }
  return 0;
}
