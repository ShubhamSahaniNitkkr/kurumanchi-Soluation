#include<iostream>
using namespace std;
#define SIZE 105

int top=-1;
char stack[SIZE];

int isEmpty()
{return(top==-1);}

int isFull()
{return(top==SIZE-1);}

void push(char n)
{if(!isFull())stack[++top]=n;return;}

void pop()
{if(!isEmpty())top--;return;}

char Top()
{if(!isEmpty())return stack[top];else return -1;}

void display()
{
  if(!isEmpty())
  for(int i=top;i>-1;i--)
   cout<<stack[i]<<endl;
  cout<<endl;
  return;
}


int isMatch(char a,char b)
{
  if(a=='{' && b=='}')
  return 1;
  else if(a=='(' && b==')')
  return 1;
  else if(a=='[' && b==']')
  return 1;
  else
  return 0;
}


int main()
{
  string s;
  int notbalanced=0;
  while(1)
  {
    cin>>s;
    for(int i=0;i<s.length();i++)
      if(s[i]=='{' || s[i]=='[' || s[i]=='(')
      {
        push(s[i]);
        continue;
      }
      else if(s[i]=='}' || s[i]==']' || s[i]==')')
      {
        if(isMatch(Top(),s[i]))
        pop();
        else
        {
          notbalanced=1;
          break;
        }
      }
      if(Top()!=-1 || notbalanced)
      cout<<"Not Balanced !"<<endl;
      else
      cout<<"Balanced !"<<endl;
  }
  return 0;
}
