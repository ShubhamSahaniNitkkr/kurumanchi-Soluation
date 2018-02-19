#include<iostream>
#include<stack>
using namespace std;

stack <char> op;
stack <char> oprnd;
stack <char> s3;

int pre(int c)
{
  switch (c){
   case '*':
   case '/':
     return 2;

    case '-':
    case '+':
      return 1;
  }
  return -1;
}

void solve(int val1,char op,int val2)
{
    switch(op){
     case '+':oprnd.push(val1 + val2);break;
     case '-':oprnd.push(val1 - val2);break;
     case '*':oprnd.push(val1 * val2);break;
     case '/':oprnd.push(val1 / val2);break;
   }
   return;
}


int main()
{
  string s;

  cin>>s;

  for(int i=0;s[i];i++)
  {
    if(s[i]>='0' && s[i]<='9' || s[i]<=')' || s[i]<='(')
    oprnd.push(s[i]);
    else
    op.push(s[i]);
  }
  for(int i=0;s[i];i++)
  {
    if(s[i]>='0' && s[i]<='9')
    {
      cout<<"char";

      if(s[i]=='(')
      op.push(s[i]);
      else if(s[i]==')')
      {
        while(op.top()!='(')
        {
          int val1=oprnd.top();oprnd.pop();
          int val2=oprnd.top();oprnd.pop();

          solve(val1,op.top(),val2);
        }
        op.pop();
      }
      else
      {
        while(!op.empty() && pre(op.top()) > pre(s[i]))
        {
          int val1=oprnd.top();oprnd.pop();
          int val2=oprnd.top();oprnd.pop();

          solve(val1,op.top(),val2);

        }
        op.push(s[i]-48);
      }
    }
    else
    {
      cout<<" oper"<<endl;
      op.push(s[i]);
    }
  }

  while(!op.empty())
  {
    int val1=oprnd.top();oprnd.pop();
    int val2=oprnd.top();oprnd.pop();

    solve(val1,op.top(),val2);

  }

  cout<<oprnd.top();
  // oprnd.pop();
  return 0;
}
