#include<iostream>
using namespace std;

void remove_adjacent_duplicates(string s)
{
  int i=0,top=-1,length=s.length();

  while(i<length)
  {
    if(top==-1 || s[i]!=s[top])
    {
      top++;
      s[top]=s[i];
      i++;
    }
    else
    {
      while(s[i]==s[top] && i<length)
      {
        i++;
        top--;
      }
    }
  }
  for(int i=0;i<=top;i++)
  cout<<s[i];
   return;
}

int main()
{
  string s="careermonk";
  remove_adjacent_duplicates(s);
  cout<<endl;
  string ss="mississippi";
  remove_adjacent_duplicates(ss);
  return 0;
}
