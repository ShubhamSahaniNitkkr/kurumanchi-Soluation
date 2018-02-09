#include<iostream>
#include<string>
using namespace std;

int main()
{
  int i,arr[256]={0};
  string s;
  cin>>s;
  int length=s.length();

  for(i=0;i<length;i++)
  {
    if(arr[s[i]]==1)
    {
      cout<<s[i]<<endl;
      break;
    }
    else
    arr[s[i]]+=1;
  }

  if(i==length)
  cout<<"Not Matching character !"<<endl;
  return 0;
}
