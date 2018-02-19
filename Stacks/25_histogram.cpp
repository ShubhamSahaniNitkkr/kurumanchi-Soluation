#include<iostream>
#include<stack>
using namespace std;


int maxArea(int arr[],int n)
{
 stack<int> s;
  int i=0,tp,max_area=0,bar_area;
  while(i<n)
  {
    if(s.empty() || arr[i]>=arr[s.top()])
      s.push(i++);
    else
    {
      tp=s.top();
      s.pop();

      bar_area = arr[tp] * (s.empty() ? i : i-s.top()-1);

      if(bar_area>max_area)
      max_area=bar_area;

    }
  }

  while(s.empty()==false)
  {
    tp=s.top();
    s.pop();

    bar_area = arr[tp] * (s.empty()?i:i-s.top()-1);

    if(bar_area>max_area)
    max_area=bar_area;

  }

  return max_area;
}

int main()
{
  int arr[]={6,2,5,4,5,1,6};
  int n = sizeof(arr)/sizeof(arr[0]);
  cout<<maxArea(arr,n);
  return 0;
}
