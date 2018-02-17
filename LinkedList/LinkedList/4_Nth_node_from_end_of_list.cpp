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

void findNode(struct node *start,int pos)
{
  struct node *p=start;
  int count,cur_pos;
  count=cur_pos=0;
  while(p!=NULL)
  {
    p=p->link;
    count++;
  }

  p=start;
  while(p!=NULL)
  {
    cur_pos++;
    if(cur_pos==count-pos+1)
    {
      cout<<p->data;
      break;
    }
   p=p->link;
  }
  return;
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


int main ()
{
  int choice,n,pos;
  struct node *start=NULL;
  while(1)
  {
    cout<<endl;
    cout<<"1.Insert"<<endl;
    cout<<"2.Find Node"<<endl;
    cout<<"3.Display"<<endl;
    cout<<"4.Exit"<<endl;
    cin>>choice;
    switch(choice){
      case 1:
      for(int i=4;i<30;i+=5)
      start=insertNode(start,i);
      Display(start);
      break;

      case 2:
      cin>>pos;
      findNode(start,pos);
      break;

      case 3:
      Display(start);
      break;

      case 4:
      exit(1);
      break;

      default:
      cout<<"Wrong Choice !"<<endl;
    }
  }
  return 0;
}
