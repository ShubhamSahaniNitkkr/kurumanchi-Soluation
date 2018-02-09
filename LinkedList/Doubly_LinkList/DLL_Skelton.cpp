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


int main() {
    struct node *start=NULL;
    int n;
    for(int i=10;i>=1;i--)
     start=insert(start,i);
        display(start);

	 return 0;
}
