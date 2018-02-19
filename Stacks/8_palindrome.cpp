#include<iostream>
using namespace std;

int main()
{
  string s;
  while(1)
  {
    cin>>s;

    int j=s.length()-1;
    int i=0;
    while(i<j && s[i]==s[j])
    {
      i++;j--;
    }

    if(i<j)
    cout<<"Not Palindrome"<<endl;
    else
    cout<<"Palindrome"<<endl;
  }

  return 0;
}
