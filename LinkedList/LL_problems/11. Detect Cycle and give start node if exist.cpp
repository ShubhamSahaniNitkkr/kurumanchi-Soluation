#include<iostream>
using namespace std;

struct node{
  int data;
  struct node *link;
};

struct node *Create(struct node *start,int data)
{
  struct node *p,*temp=(struct node *)malloc(sizeof(struct node));
  temp->data=data;
  temp->link=NULL;
  if(!start)
  return temp;

  p=start;
  while(p->link!=NULL)
   p=p->link;
  p->link=temp;
  return start;
}


void Display(struct node *start)
{
  struct node *p=start;
  while(p!=NULL)
  {
    cout<<p->data<<" ";
    p=p->link;
  }
  cout<<endl;
  return;
}

void loop_detector(struct node *start)
{
  int loop=0;
  struct node *slwptr,*fstptr;
  slwptr=fstptr=start;

  while(slwptr && fstptr && fstptr->link)
  {
    slwptr=slwptr->link;
    fstptr=fstptr->link->link;

    if(slwptr==fstptr)
    {loop=1;break;}
  }
  if(loop)
  {
    slwptr=start;
    while(slwptr!=fstptr)
    {
      slwptr=slwptr->link;
      fstptr=fstptr->link;
    }
      cout<<" Found at "<<slwptr->data<<endl;
      return;
  }
  cout<<"Not Fund !"<<endl;
  return;
}

int main()
{
  struct node *p,*start=NULL;
  for(int i=0;i<56;i+=3)
    start=Create(start,i);

  //make cyclic
  p=start;
  while(p->link->link!=NULL)
   p=p->link;
  p->link=start->link;

  //loop detector function
  loop_detector(start);

  // Display(start);
  return 0;
}
