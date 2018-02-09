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

int findlength(struct node *start)
{
  struct node *p=start;
  int count=0;
  while(p!=NULL)
  {
    count++;
    p=p->link;
  }
  return count;
}

int shownode(struct node *start,int length)
{
  struct node *p=start;
  int pos=1;
  while(p->link!=NULL)
  {
    if(pos==length)
    break;
    p=p->link;
    pos++;
  }
  return p->data;
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
      int actualLength=findlength(start);
      if(length<=actualLength && length>0)
      {
        cout<<shownode(start,actualLength-length+1)<<endl;
      }
      else
      cout<<"Position Does not exist !"<<endl;

    }
	 return 0;
}
