#include<iostream>
using namespace std;

int main()
{
  int arr[]={6,3,4,5,2};
  int s[]={1,1,1,1,1};
  for(int i=0;i<5;i++)
  {
    int j=1;
    while(arr[i]>arr[i-j] && i>=j)
    {
      j++;
      s[i]=j;
    }
  }
  for(int i=0;i<5;i++)
  cout<<s[i]<<" ";
  return 0;
}
