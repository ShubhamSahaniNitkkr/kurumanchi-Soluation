#include<iostream>
using namespace std;

struct node{
  int data;
  struct node *link;
};



int count(struct node *start)
{
  struct node *p=start;
  int count=0;
  do {
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


  struct node *delete_circular_link_list(struct node *start,int pos)
  {
    struct node *temp,*p=start;

    if(!start)
      return start;

    if(count(start)==1)
    {
      start=NULL;
      return start;
    }

    if(pos==count(start))
    {
      while(p->link->link!=start)
       p=p->link;

      temp=p->link;
      p->link=temp->link;
      return start;
    }
    else if(pos==1)
    {
      while(p->link!=start)
       p=p->link;

       temp=p->link;
       start=temp->link;
       p->link=start;
       free(temp);
       return start;
    }
    else
    {
      int pass=0;
      do
      {
        if(pass==pos-2)
        {
          temp=p->link;
          p->link=temp->link;
          free(temp);
          return start;
        }
        p=p->link;
        pass++;
      }while(p!=start);
    }
    return start;
  }


void Display(struct node *start)
{
  struct node *p=start;
  if(!start)
  {
    cout<<"Empty List"<<endl;
    return ;
  }
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
  int pos;
  struct node *start=NULL;
  cout<<"Press 0 to exit !"<<endl;
  for(int i=1;i<12;i++)
   start=circular_link_list(start,i,i);

   Display(start);

    while(1)
    {
      cin>>pos;
      if(pos==0){exit(1);}
      start=delete_circular_link_list(start,pos);
      Display(start);

    }

  return 0;
}
