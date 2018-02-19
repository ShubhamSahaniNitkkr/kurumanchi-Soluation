#include<iostream>
#include<string>
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

int checkprec(char c)
{
  switch (c) {
    case '^':
    return 3;

    case '*':
    case '/':
    return 2;

    case '+':
    case '-':
    return 1;

  }
  return -1;
}



int main()
{
  string s,result;
  cin>>s;

  for(int i=0;i<s.length();i++)
  {
    if((s[i]>='a' && s[i]<='z' )|| (s[i]>='A' && s[i]<='Z'))
     result+=s[i];
    else if(s[i]=='(')
     push(s[i]);
    else if(s[i]==')')
    {
      while(Top()!='(' && Top()!=-1)
      {
        result+=Top();
        pop();
      }
      pop();// to remove )
    }
    else
    {
        while(checkprec(s[i])<=checkprec(Top()) && Top()!=-1)
        {
          result+=Top();
          pop();
        }
        push(s[i]);
    }
    // cout<<"on each"<<result<<endl;
  }
  if(Top()!=-1)//if remain in stack
  {
    result+=Top();
    pop();
  }
  cout<<result;

  return 0;
}
