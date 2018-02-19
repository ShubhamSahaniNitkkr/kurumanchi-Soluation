#include<iostream>
#include<stack>
#include<queue>
using namespace std;

int main()
{
  int arr[]={5,4,3,2,1};
  stack <int> s;
  for(int i=0;i<5;i++)
  s.push(arr[i]);

  while(!s.empty())
  {
    cout<<s.top()<<" ";
    s.pop();
  }
  return 0;
}
