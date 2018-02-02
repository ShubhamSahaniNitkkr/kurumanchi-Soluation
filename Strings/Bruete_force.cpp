#include<iostream>
using namespace std;

int main()
{
  int t,i,j,flag;
  cin>>t;
  while(t--)
  {
    string s,p;
    flag=0;
    cin>>s>>p;

    for(i=0;i<s.length()-p.length()+1;i++)
    {
      j=0;
      while(j<p.length() && p[j]==s[i+j])
       j+=1;

      if(j==p.length())
      {
        cout<<"found it at "<<i+1<<endl;
        flag=1;
        break;
      }
    }
    if(flag==0)
    cout<<"Not found !"<<endl;
  }
  return 0;
}
