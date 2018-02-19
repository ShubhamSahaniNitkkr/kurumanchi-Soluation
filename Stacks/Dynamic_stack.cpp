#include<iostream>
using namespace std;

struct stack{
  int top;
  int size;
  int *array;
};

struct stack *size_double(struct stack *start)
{
  start->size=2*start->size;
  start->array=(int *)realloc(start->array,start->size * sizeof(int));
  return start;
}

int isFull(struct stack *start)
{
  return (start->top==start->size-1);
}

int isEmpty(struct stack *start)
{
  return (start->top==-1);
}

struct stack *create(struct stack *start){

    struct stack *temp=(struct stack *)malloc(sizeof(struct stack));
    temp->top=-1;
    temp->size=1;
    temp->array=(int *)malloc(temp->size*sizeof(int));
    return temp;
}


struct stack *push(struct stack *start,int n){

  if(isFull(start))
  start=size_double(start);
    start->array[++start->top]=n;
  return start ;
}

void pop(struct stack *start)
{
  if(!isEmpty(start))
    cout<<start->array[start->top--];
  else
  cout<<"Array is Empty!"<<endl;
  return;
}

void Top(struct stack *start){
  if(!isEmpty(start))
  cout<<start->array[start->top];
  else
  cout<<"Array is Empty!"<<endl;
  return;
}

void display(struct stack *start)
{
  if(!isEmpty(start))
  {
    for(int i=start->top;i>=0;i--)
    cout<<start->array[i]<<" ";
    cout<<endl;
  }
  else
  cout<<"Array is Empty!"<<endl;
  return;
}

int main()
{
  int choice,n;
  struct stack *start=create(start);
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
      start=push(start,n);
      display(start);
      break;

      case 2:
      pop(start);
      break;

      case 3:
      Top(start);
      break;

      case 4:
      display(start);
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
