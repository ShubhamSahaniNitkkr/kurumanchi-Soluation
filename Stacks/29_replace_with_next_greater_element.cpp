#include<iostream>
#include<stack>
using namespace std;

void next_adj_greater(int arr[],int n)
{
  int element,next;
  stack <int> s;
  s.push(arr[0]);

  for(int i=1;i<n;i++)
  {
    next=arr[i];

    if(!s.empty())
    {
      element=s.top();
      s.pop();
      while(next>element)
      {
        cout<<element<<"->"<<next<<endl;
        if(s.empty())
         break;
        element=s.top();
        s.pop();

      }
      if(element>next)
      s.push(element);

    }
    s.push(next);
  }
    while(!s.empty())
    {
      cout<<s.top()<<" Greatest from the Right !!"<<endl;
      s.pop();
    }
  return;
}

int main()
{
  int next,arr[]={11, 13, 21, 3};
  int n=4;
  for(int i=0;i<4;i++)
  cout<<arr[i]<<" ";
  cout<<endl;
  next_adj_greater(arr,n);

  return 0;
}
