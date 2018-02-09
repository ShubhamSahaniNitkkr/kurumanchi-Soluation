#include <iostream>
using namespace std;

struct node{
    int data;
    struct node *link;
};



void display(struct node *start)
{
    struct node *p=start;
    cout<<"List is ";
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->link;
    }
    cout<<endl;
}

struct node *insert(struct node *start,int data)
{
    struct node *p,*temp=(struct node *)malloc(sizeof(struct node));
    temp->data=data;
    temp->link=NULL;

    if(start==NULL)
     return temp;
     p=start;
    while(p->link!=NULL)
     p=p->link;
    p->link=temp;
    return start;
}

int search(struct node *start,int data)
{
  struct node *p=start;
  while(p!=NULL)
  {
    if(p->data==data)
    return 1;
    p=p->link;
  }
  return -1;
}

struct node *Delete(struct node *start,int n)
{
  if(search(start,n)!=-1)
  {
    struct node *p,*temp=NULL;
    if(start->data==n)
    {
      temp=start;
      start=temp->link;
      free(temp);
      return start;
    }
    p=start;
    while(p->link!=NULL)
    {
      if(p->link->data==n)
      {
        temp=p->link;
        p->link=temp->link;
        free(temp);
        return start;
      }
      p=p->link;
    }
  }
  else
  cout<<"Number Not Found"<<endl;
  return start;
}


int main() {
    struct node *start=NULL;
    int n;
    for(int i=1;i<=10;i++)
     start=insert(start,i);
        display(start);
    while(1)
    {
      cin>>n;
      if(n==0)
      exit(1);
      start=Delete(start,n);
      display(start);
    }
	 return 0;
}
