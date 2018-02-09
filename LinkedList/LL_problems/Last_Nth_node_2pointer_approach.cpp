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

struct node *shownode(struct node *start,int lastNthNode)
{
  struct node *temp1,*temp=start;
  temp1=NULL;
  for(int count=1;count<lastNthNode;count++)
  {
    if(temp)
    temp=temp->link;
  }

  while(temp)
  {
    if(temp1==NULL)
      temp1=start;
    else
     temp1=temp1->link;

    temp=temp->link;
  }

  if(!temp1)
  {
    cout<<"Position does'nt exist"<<endl;
    return start;
  }
  cout<<temp1->data<<endl;
  return start;
}


int main() {
    struct node *start=NULL;
    int n,length;
    for(int i=1;i<=4;i++)
     start=insert(start,i);
        display(start);

    cout<<endl<<"Formula: Total_length-Positon_to_find+1"<<endl;
    cout<<endl<<"Enter -1 to Exit !"<<endl;
    while(1)
    {
      cin>>length;
      if(length==-1){exit(1);}
      start=shownode(start,length);
    }
	 return 0;
}
