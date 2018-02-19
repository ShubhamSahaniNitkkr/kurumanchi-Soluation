#include<iostream>
#include<stack>
using namespace std;


int main()
{
  stack <int> s1;
  stack <int> s2;
  stack <int> s3;

  int choice,n,flag=1;

  while(1)
  {
    cout<<endl;
    cout<<"1.push"<<endl;
    cout<<"2.pop"<<endl;
    cout<<"3.Min"<<endl;
    cout<<"4.Display"<<endl;
    cout<<"5.Exit"<<endl;
    cin>>choice;
    switch (choice) {
      case 1:

      cin>>n;
      s1.push(n);
      if(flag)
      {
        s2.push(n);
        flag=0;
        continue;
      }
      else
      {
        if(s2.top()>s1.top())
        s2.push(n);
      }
      break;

      case 2:
      if(!s2.empty() && !s1.empty())
      if(s1.top()==s2.top())
      {
        s1.pop();
        s2.pop();
      }
      else if(!s1.empty())
      s1.pop();

      case 3:
      if(!s2.empty())
      cout<<endl<<s2.top()<<endl;
      break;

      case 4:
      s3=s1;
      while(!s3.empty())
      {
        cout<<s3.top()<<"->";
        s3.pop();
      }
      break;

      case 5:
      exit(1);
    }
  }
  return 0;
}
