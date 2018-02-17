#include<iostream>
using namespace std;

struct node{
  int data;
  struct node *link;
};

struct node *create(struct node *start,int data)
{
  struct node *p=start,*temp=(struct node *)malloc(sizeof(struct node));
  temp->data=data;
  temp->link=temp;

  if(!start)
    return temp;

  while(p->link!=start)
   p=p->link;

  temp->link=start;
  p->link=temp;
  return start;
}

void Display(struct node *start)
{
    struct node *p=start,*start1,*start2;
      do{
      cout<<"->"<<p->data;
      p=p->link;
    }while(p!=start);

    cout<<endl;
  return;
}

struct node *split(struct node *start)
{
  if(!start)
  return start;
  struct node *start1=NULL,*start2=NULL;

  struct node *slw,*fst;
  slw=fst=start;

  while(fst->link!=start && fst->link->link!=start)
  {
    slw=slw->link;
    fst=fst->link->link;
  }

  //if even number then fst pointer will pint to head
  if(fst->link->link==start)
   fst=fst->link;

   //initalizing 1st half head
   start1=start;

   //initalizing 2nd half head
   if(start->link!=start)
   start2=slw->link;

   //making cyclic 2nd half head
   fst->link=slw->link;

   //making cyclic 1st half head
   slw->link=start;

   Display(start1);
   Display(start2);


  return start;
}

int main()
{
  struct node *start=NULL,*start1=NULL,*start2=NULL;
  for(int i=5;i<55;i+=5)
  start=create(start,i);
  Display(start);
  start=split(start);
  return 0;
}
