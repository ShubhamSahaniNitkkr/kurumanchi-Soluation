#include<iostream>
#include<stack>
using namespace std;


int main()
{
  int notPalindrome=0;
  stack <char> s;
  string name;
  cin>>name;

  for(int i=0;i<name.length();i++)
   s.push(name[i]);

   for(int i=0;i<name.length();i++)
   {
     if(name[i]!=s.top())
     {
       notPalindrome=1;
       break;
     }
     s.pop();
   }
   if(notPalindrome)
   cout<<"Not Palindrome !"<<endl;
   else
   cout<<"Palindrome !"<<endl;

  return 0;
}
