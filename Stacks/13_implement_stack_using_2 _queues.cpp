#include<iostream>
#include<queue>
using namespace std;

int main()
{
  queue <int> q1;
  queue <int> q2;
  int n;
  int choice;
  while(1)
  {
    cout<<endl<<"1.Push";
    cout<<"2.Pop"<<endl;
    cin>>choice;

    switch(choice)
    {
      case 1:
      cin>>n;
      if(q1.empty() && q2.empty())
      {
        q1.push(n);
        continue;
      }
      else if(!q1.empty())
      {
        q1.push(n);
      }
      else if(!q2.empty())
      {
        q2.push(n);
      }
      break;

      case 2:
      if(!q1.empty())
      {
        while(q1.size()>1)
        {
          q2.push(q1.front());
          q1.pop();
        }
        cout<<"->"<<q1.front()<<endl;
        q1.pop();
      }
      else if(!q2.empty())
      {
        while(q2.size()>1)
        {
          q1.push(q2.front());
          q2.pop();
        }
        cout<<"->"<<q2.front()<<endl;
        q2.pop();
      }
      break;
    }
  }
  return 0;
}
