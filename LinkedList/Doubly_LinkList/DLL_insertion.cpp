#include<iostream>
using namespace std;

struct node{
  int data;
  struct node *prev,*next;
};


int search(struct node *start,int n)
{
  struct node *p=start;
  while(p!=NULL)
  {
    if(p->data==n)
    return 1;
    p=p->next;
  }
  return -1;
}

struct node *insert(struct node *start,int data)
{
   struct node *p,*temp=(struct node *)malloc(sizeof(struct node));
   int pos;
    temp->data=data;
    cout<<"Where You want to insert "<<"1.Begin "<<"2.Last "<<"3.Insert after "<<"4<<insert before "<<endl;
    cin>>pos;

    if(start==NULL || pos==1)
    {
      temp->next=start;
      temp->prev=NULL;
      if(start)
        start->prev=temp;
      start=temp;
      return start;
    }

    switch (pos){
    case 2:
    {
        p=start;
        while(p->next!=NULL)
        p=p->next;

        p->next=temp;
        temp->prev=p;
        temp->next=NULL;
        return start;
    }
    case 3:
    {
      int num;
      cout<<"Enter the number after you want to insert"<<endl;
      cin>>num;
      if(search(start,num)!=-1)
      {
        p=start;
        while(p->next!=NULL)
        {
          if(p->data==num)
          {
            temp->next=p->next;
            temp->prev=p->next->prev;
            p->next=temp;
            p->next->prev=temp;
            return start;
          }
          p=p->next;
        }
      }
      else
      {
        cout<<"Your digit does'nt found in the list !"<<endl;
        return start;
      }

    }

    case 4:
    {
      int num;
      cout<<"Enter the number after you want to insert"<<endl;
      cin>>num;
      if(search(start,num)!=-1)
      {
        p=start;
        while(p->next!=NULL)
        {
          if(p->next->data==num)
          {
            temp->next=p->next;
            temp->prev=p->next->prev;
            p->next=temp;
            p->next->prev=temp;
            return start;
          }
          p=p->next;
        }
      }
      else
      {
        cout<<"Your digit does'nt found in the list !"<<endl;
        return start;
      }

    }

    }
    return start;
}




void display(struct node *start)
{
  struct node *p=start;
  cout<<"List is ";
  while(p!=NULL)
  {
    cout<<p->data;
    p=p->next;
  }
  cout<<endl;
  return;
}


int main()
{
  int n;
  struct node *start=NULL;
  while(1)
  {
    cin>>n;
    if(n==0){exit(1);}
    start=insert(start,n);
    display(start);
  }
  return 0;
}
