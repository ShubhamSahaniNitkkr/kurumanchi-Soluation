#include<iostream>
using namespace std;

struct Queue{
  int front,rear,size,*arr;
  Queue(int s){
    front=rear=-1;
    size=s;
    arr= new int[s];
  }
  void enqueue(int n);
  int dqueue();
  void display();

};

void Queue ::enqueue(int n)
{
  if(front==0 && rear ==size-1)
  {
    cout<<"Doubling Size"<<endl;
    size=2*size;
  }
  if(front==-1)
  {
    front=rear=0;
    arr[rear]=n;
  }
  else if(front !=0 && rear ==size-1)
  {
    rear=0;
    arr[rear]=n;
  }
  else
  {
    rear=rear+1;
    arr[rear]=n;
  }
  return;
}



int Queue ::dqueue()
{
  if(front==-1)
  {
    cout<<"Empty"<<endl;
    return INT_MIN;
  }

  int data=arr[front];
  arr[front]=-1;

  if(front==rear)
    front=rear=-1;
  else if(front==size-1)
    front=0;
  else
    front++;
  return data;
}



void Queue ::display()
{
  if(front==-1)
  {
    cout<<"Empty"<<endl;
    return ;
  }
  if(rear>front)
  {
    for(int i=front;i<=rear;i++)
    cout<<arr[i]<<" ";
  }
  else
  {
    for(int i=front;i<size;i++)
    cout<<arr[i]<<" ";

    for(int i=front;i<rear;i++)
    cout<<arr[i]<<" ";
  }
  return;
}




int main()
{
  int size;
  cin>>size;
  Queue q(size);
  int choice,n;
  while(1)
  {
    cout<<endl<<"1.Enqueue"<<endl;
    cout<<"2.Deque"<<endl;
    cout<<"3.Display"<<endl;
    cout<<"4.Exit"<<endl;
    cin>>choice;

    switch (choice) {
      case 1:
      cin>>n;
      q.enqueue(n);
      break;

      case 2:
      q.dqueue();
      break;

      case 3:
      q.display();
      break;

      case 4:
      exit(1);
      break;

      default:
      cout<<"Wrong choice"<<endl;
    }

  }
  return 0;
}
