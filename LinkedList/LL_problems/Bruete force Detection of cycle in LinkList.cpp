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
    int n=0;
    while(p!=NULL && n < 100)
    {
        cout<<p->data<<" ";
        p=p->link;
        n++;
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

struct node *makecyclic(struct node *start)
{
  struct node *dummy,*p=start;
  while(p->link!=NULL)
    p=p->link;
   p->link=start;

  return start;
}

void checkcycle(struct node *start)
{
  struct node *temp,*p1,*p=start;
  while(p->link!=NULL)
  {
    temp=p;
    p1=start;
    while(p1->link!=NULL)
    {
      if(p1->link==temp)
      {
        cout<<"Cycle Found at "<<p->data;
        return;
      }
      p1=p1->link;
    }
    p=p->link;
  }
  return;
}



int main() {
    struct node *start=NULL;
    int n,length;
    for(int i=1;i<=10;i++)
     start=insert(start,i);
     start=makecyclic(start);
      display(start);

        checkcycle(start);

	 return 0;
}
