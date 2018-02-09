#include <iostream>
using namespace std;

struct node{
    int data;
    struct node *prev,*next;
};



void display(struct node *start)
{
    struct node *p=start;
    cout<<"List is ";
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}


int length(struct node *start)
{
  struct node *p=start;
  int k=0;
  while(p!=NULL)
  {
    p=p->next;
    k++;
  }
  return k;
}


int search(struct node *start,int data)
{
  struct node *p=start;
  while(p!=NULL)
  {
    if(p->data==data)
    return 1;
    p=p->next;
  }
  return -1;
}

struct node *insert(struct node *start,int data)
{
    struct node *p,*temp=(struct node *)malloc(sizeof(struct node));
    temp->data=data;
    temp->prev=temp->next=NULL;
    if(!start)
    return temp;

    p=start;
    while(p->next!=NULL)
     p=p->next;

    p->next=temp;
    temp->prev=p;
    temp->next=NULL;
    return start;
}

struct node *Delete(struct node *start,int n)
{
  struct node *temp,*temp1,*p;

      if(n==1)
      {
        temp=start;
        start=start->next;
        if(start)
        start->prev=NULL;
        free(temp);
        return start;
      }

      int pass=1;
        p=start;
        while(p->next!=NULL)
        {
          if(pass==n-1)
          {
            temp=p->next;
            p->next = temp->next;
            if(temp->next)
              p->next->prev=p->next;
            free(temp);
            return start;
          }
          pass++;
          p=p->next;
        }

  return start;
}



int main() {
    struct node *start=NULL;
    int n;
    for(int i=10;i>=1;i--)
     start=insert(start,i);
        display(start);
    while(1)
    {
      cin>>n;
      if(n==0){exit(1);}
      if(length(start)>=n)
      {
        start=Delete(start,n);
        display(start);
      }
      else
      {
        cout<<"Length Does'nt Exist !"<<endl;
      }
    }

	 return 0;
}
