#include<iostream>
#include<stack>
using namespace std;

void cSpan(int stock[],int n,int span[])
{
  stack <int> s;
  span[0]=1;
  s.push(0);

  for(int i=0;i<n;i++)
  {
    while(!s.empty() && stock[i]>=stock[s.top()])
    {
      s.pop();
    }
    span[i]=(s.empty()) ? (i+1) : (i-s.top());
    s.push(i);
  }
  for(int i=0;i<n;i++)
  cout<<span[i]<<" ";

  return;
}


int main()
{
    int stock[] = {10, 4, 5, 90, 120, 80};
    int n = sizeof(stock)/sizeof(stock[0]);
    int span[n];
    cSpan(stock,n,span);
    return 0;
}
