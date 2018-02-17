#include<iostream>
using namespace std;
struct node{
  int data;
  struct node *link;
};

struct node *insertNode(struct node *start,int n)
{
  struct node *p,*temp=(struct node *)malloc(sizeof(struct node));
  temp->data=n;
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


void cycleLength(struct node *start)
{
  int count,loop;
  struct node *slw,*fst;
  slw=fst=start;
  count=loop=0;

  while(slw && fst && fst->link)
  {
    slw=slw->link;
    fst=fst->link->link;
    if(slw==fst)
    {
      loop=1;
      break;
    }
  }
  if(loop)
  {
    slw=start;
    while(slw!=fst)
    {
      slw=slw->link;
      fst=fst->link;
      count++;
    }
    cout<<"Loop exist at "<<slw->data<<" and its length is "<<count<<endl;
    return;
  }
  cout<<"Loop Does'nt exist !"<<endl;
  return;
}

int main ()
{
  int choice;
  struct node *p,*start,*start1;
  start=start1=NULL;

  for(int i=4;i<30;i+=5)
  start=insertNode(start,i);
  Display(start);

  for(int i=4;i<30;i+=5)
  start1=insertNode(start1,i);

  //making link cyclic
  p=start;
   while(p->link!=NULL)
    p=p->link;
  p->link=p;

  cycleLength(start);
  cycleLength(start1);


  return 0;
}
