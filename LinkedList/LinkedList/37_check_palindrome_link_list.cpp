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
  cout<<endl;
  return;
}

struct node *reverse(struct node *start)
{
  if(!start)
  return start;

  struct node *temp=NULL,*q=NULL,*p=start;
  while(p)
  {
    q=p->link;
    p->link=temp;
    temp=p;
    p=q;
  }
  return temp;
}

void compare(struct node *s1,struct node *s2)
{
  while(s1 && s2)
  {
    if(s1->data!=s2->data)
    {
      cout<<"Not Palindrome"<<endl;
      return;
    }
    s1=s1->link;
    s2=s2->link;
  }
  cout<<"Palindrome"<<endl;
  return;
}
void checkPalindrome(struct node *start)
{

  struct node *fst,*slw,*s1,*s2;
  fst=slw=start;
  s1=start;
  while(1)
  {
    fst=fst->link->link;
    if(!fst)
    {
      s2=slw->link;
      break;
    }
    if(!fst->link)
    {
      s2=slw->link->link;
      break;
    }
    slw=slw->link;
  }
  slw->link=NULL;

   s2=reverse(s2);
   compare(s1,s2);
  return ;
}


int main ()
{
  int choice;
  struct node *start=NULL;

  for(int i=1;i<=3;i++)
  start=insertNode(start,i);
  for(int i=4;i>=1;i--)
  start=insertNode(start,i);
  Display(start);
  checkPalindrome(start);

  struct node *start1=NULL;
  for(int i=1;i<=7;i++)
  start1=insertNode(start1,i);

  Display(start1);
  checkPalindrome(start1);
  return 0;
}
