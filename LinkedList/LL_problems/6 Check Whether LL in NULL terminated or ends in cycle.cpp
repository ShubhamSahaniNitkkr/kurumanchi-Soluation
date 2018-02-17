//20 minutes
#include <iostream>
using namespace std;

struct node{
    int data;
    struct node *link;
};


struct node *insert(struct node *start,int data)
{
    struct node *q,*p,*temp=(struct node *)malloc(sizeof(struct node));
    temp->data=data;
    temp->link=NULL;

    if(start==NULL)
     return temp;
     p=start;
    while(p->link!=NULL)
    {
      {
        if(p->link->link==NULL)
        q=p->link;
      }
       p=p->link;
    }
    p->link=temp;
    return start;
}

void cycle_detector(struct node *start)
{
  struct node *one,*two;
  one=two=start;

  while(one && two)
  {
    cout<<one->data<<" ";
    one=one->link;
    two=two->link->link;

    if(one==two)
    {
      cout<<"loop found at"<<one->data<<endl;
      return;
    }
  }
  cout<<"loop Not found !"<<endl;
  return;
}


int main() {
    struct node *q,*p,*start=NULL;
    for(int i=3;i<=30;i+=3)
     start=insert(start,i);

     //making list cyclclic
     q=start;
     while(q->link!=NULL)
     q=q->link;
     q->link=start;
    cycle_detector(start);

    struct node *start1=NULL;
    for(int i=3;i<=30;i+=3)
    start1=insert(start1,i);
    cycle_detector(start1);

	 return 0;
}
