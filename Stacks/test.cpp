#include<iostream>
#include<stack>
using namespace std;

bool isChar(string s)
{
     if(s.size() >1 ) return false;

     switch (s[0]) {
        case '+': return true;
        case '-': return true;
        case '*': return true;
        case '/': return true;
        case '(': return true;
        case ')': return true;
        case '^': return true;
        default: return false;
    }
}

int solve(int op1, int op2, char ch)
{
     switch(ch)
     {
          case '+': return (op1+op2);
          case '-': return (op1-op2);
          case '*': return (op1*op2);
          case '/': return (op1/op2);
     }
     return -1;
}

int preference( char ch)
{
     switch(ch)
     {
          case '+': return 1;
          case '-': return 1;
          case '*': return 2;
          case '/': return 2;
          case '^': return 3;
          case '(': return -1;
     }
     return -1;
}

void evaluate(string s1)
{
     stack<char> operators;
     stack<int> operands;

     string s;
     while(s.length())
     {
          if(isChar(s))
          {
               if(s[0]=='(') operators.push('(');
               else if(s[0]==')')
               {
                    while(operators.top()!='(')
                    {
                         char ch=operators.top(); operators.pop();
                         int op2=operands.top(); operands.pop();
                         int op1=operands.top(); operands.pop();

                         operands.push(solve(op1,op2,ch));
                    }
                    operators.pop();
               }
               else
               {
                    while(!operators.empty() &&   preference(s[0]) <= preference(operators.top()))
                    {
                         char ch=operators.top(); operators.pop();
                         int op2=operands.top(); operands.pop();
                         int op1=operands.top(); operands.pop();

                         operands.push(solve(op1,op2,ch));

                    }

                    operators.push(s[0]);
               }

          }
          else
          {
               int op=atoi(s.c_str());
               operands.push(op);
          }

     }

     while(!operators.empty())
     {
          char ch=operators.top(); operators.pop();
          int op2=operands.top(); operands.pop();
          int op1=operands.top(); operands.pop();

          operands.push(solve(op1,op2,ch));
     }

     //cout<<operands.empty()<<" "<<operators.empty();
     cout<<"result: "<<operands.top()<<endl;
}

int main()
{
     int t;

          string s="2 + 3 * 5 + ( 2 * 3 )";
          //cin>>s;
          evaluate(s);

     return 0;
}
