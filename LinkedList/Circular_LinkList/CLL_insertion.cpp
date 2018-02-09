#include<iostream>
using namespace std;

struct node{
  int data;
  struct node *link;
};



int length(struct node *start)
{
  struct node *p=start;
  int count=0;
  do {
    cout<<p->data<<" ";
    p=p->link;
    count++;
  } while(p!=start);
  return count;
}


struct node *circular_link_list(struct node *start,int data,int pos)
{
  struct node *p,*temp=(struct node *)malloc(sizeof(struct node));
  temp->data=data;
  temp->link=temp;

  if(start==NULL)
  return temp;


    p=start;
    int pass=2;
    while(p->link!=start)
    {
      if(pass==pos)
      {
        temp->link=p->link;
        p->link=temp;
        return start;
      }
      p=p->link;
      pass++;
    }

    temp->link=start;
    p->link=temp;
    if(pos==1)
     start=temp;
  return start;

}

void Display(struct node *start)
{
  struct node *p=start;

  cout<<endl<<"List is"<<endl;
  do {
    cout<<p->data<<" ";
    p=p->link;
  } while(p!=start);
  cout<<endl;
  return;
}


int main()
{
  int pos,n;
  struct node *start=NULL;
  cout<<"Press 0 to exit !"<<endl;
  while(1)
  {
    cin>>n;
    if(n==0){exit(1);}
    cin>>pos;
      start=circular_link_list(start,n,pos);
      Display(start);
  }

  return 0;
}
