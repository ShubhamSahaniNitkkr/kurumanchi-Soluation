#include<iostream>
using namespace std;
#define SIZE 5

int arr[SIZE];
int top1=-1;
int top2=SIZE-1;


void push1(int n)
{
  if(top1+1!=top2)//if space resides
  arr[++top1]=n;
  else
  cout<<"Full !"<<endl;
  return;
}

void push2(int n)
{
  if(top1+1!=top2)//if space resides
  {
    top2=top2-1;
    arr[top2]=n;
  }
  else
  cout<<"Full !"<<endl;
  return;
}

void pop1()
{
  int n;
  if(top1!=-1)
  {
    n=arr[top1--];
    cout<<"Popped ->"<<n<<endl;
    return;
  }
  return;
}

void pop2()
{
  int n;
  if(top2!=SIZE-1)
  {
    n=arr[top2++];
    cout<<"Popped ->"<<n<<endl;
    return;
  }
  else
  cout<<"stack is Empty"<<endl;
  return;
}

void display()
{
  for(int i=top1;i>=0;i--)
  {
    if(arr[i]!=0)
    cout<<arr[i]<<" ";
  }
  cout<<endl;

  for(int i=top2;i<=SIZE-1;i++)
  {
    if(arr[i]!=0)
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}

int main()
{

  int choice,n;
  while(1)
  {
    cout<<endl<<"1.Push1"<<endl;
    cout<<"2.Push2"<<endl;
    cout<<"3.Pop1"<<endl;
    cout<<"4.Pop2"<<endl;
    cout<<"5.Exit"<<endl;
    cin>>choice;

    switch (choice) {
      case 1:
      cin>>n;
      push1(n);
      display();
      break;

      case 2:
      cin>>n;
      push2(n);
      display();
      break;

      case 3:
      pop1();
      display();
      break;

      case 4:
      pop2();
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
