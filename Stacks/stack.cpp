#include<iostream>
using namespace std;
#define SIZE 5

int top=-1,stack[SIZE];

int isEmpty()
{return(top==-1);}

int isFull()
{return(top==SIZE-1);}

void push(int n)
{if(!isFull())stack[++top]=n;return;}

void pop()
{if(!isEmpty())top--;return;}

int Top()
{if(!isEmpty())return stack[top];else return -1;}

void display()
{
  if(!isEmpty())
  for(int i=top;i>-1;i--)
   cout<<stack[i]<<" ";
  cout<<endl;
  return;
}

int main()
{
  int choice,n;
  while(1)
  {
    cout<<"1.Push"<<endl;
    cout<<"2.Pop"<<endl;
    cout<<"3.Top"<<endl;
    cout<<"4.Display"<<endl;
    cout<<"5.Exit"<<endl;
    cin>>choice;

    switch (choice) {
      case 1:
      cin>>n;
      push(n);
      display();
      break;

      case 2:
      pop();
      display();
      break;

      case 3:
      cout<<Top();
      break;

      case 4:
      if(isEmpty())
      cout<<"List is Empty"<<endl;
      else
      display();
      break;

      case 5:
      exit(1);
      break;

      default:
      cout<<"Wrong choice"<<endl;
    }

  }
  return 0;
}
