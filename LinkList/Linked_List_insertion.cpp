#include <iostream>
using namespace std;

struct node{
    int data;
    struct node *link;
};



int search(struct node *start,int num)
{
  struct node *p=start;
  while(p!=NULL)
  {
      if(p->data==num)
      {
        return 1;
      }
      p=p->link;
  }
    return -1;
}

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
    if(start==NULL)
    {
      temp->link=NULL;
      return temp;
    }

    p=start;
    int pos;
    cout<<"Where you want to insert this number "<<endl;
    cout<<"1.Begining"<<endl;
    cout<<"2.Middle"<<endl;
    cout<<"3.Last"<<endl;
    cin>>pos;
    switch (pos) {
      case 1:
      {
        temp->link=start;
        start=temp;
        return start;
      }
      break;
      case 2:
      {
        int num;
        cout<<"Insert The Number after or before you want to insert"<<endl;
        cin>>num;
        if(search(start,num)!=-1)
        {
          cout<<"You want to insert "<<endl;
          cout<<"1. Before "<<num<<endl;
          cout<<"2. After "<<num<<endl;
          cin>>pos;
          if(pos==1)
          {
            while(p->link->data!=num)
            {
              p=p->link;
            }
            temp->link=p->link;
            p->link=temp;
          }
          else
          {
            while(p->link->data!=num)
            {
              p=p->link;
            }
            p=p->link;
            temp->link=p->link;
            p->link=temp;
          }
        }
        else
        cout<<"Your number does'nt Exist in the list";
      }
      break;
      case 3:
      {
        temp->link=NULL;
        while(p->link!=NULL)
        p=p->link;
        p->link=temp;
        return start;
      }
      break;
      default:
      cout<<"Invalid Choice"<<endl;
    }
    return start;
}


int main() {
    struct node *start=NULL;
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<endl;
        start=insert(start,n);
        display(start);
    }
	 return 0;
}
