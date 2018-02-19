#include<iostream>
using namespace std;
#define SIZE 5

int top=-1;int stack[SIZE];

int isEmpty(){return(top==-1);}

int isFull(){return(top==SIZE-1);}

void push(int n){if(!isFull())stack[++top]=n;return;}

char pop()
{
  int n;
  if(!isEmpty())
  {
    n=stack[top];
    top--;
    return n;
  }
  return -1;
}

int main()
{
  string s,result;
  cin>>s;
  for(int i=0;i<s.length();i++)
  {
    if(s[i]>='0' && s[i]<='9')
    push(s[i]-48);
    else
    {
      int val1 = pop();
      int val2 = pop();
      switch (s[i])
      {
       case '+': push(val2 + val1); break;
       case '-': push(val2 - val1); break;
       case '*': push(val2 * val1); break;
       case '/': push(val2/val1);   break;
      }
    }
  }
  cout<<int(pop());

  return 0;
}
