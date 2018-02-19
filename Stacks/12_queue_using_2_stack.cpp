#include<iostream>
#include<stack>
using namespace std;

int main()
{
  int choice,n;
  stack <int> enque;
  stack <int> deque;
  stack <int> temp;
  while(1)
  {
    cout<<"1.Push"<<endl;
    cout<<"2.Pop"<<endl;
    cin>>choice;

    switch (choice)
    {
      case 1:
      cin>>n;
      enque.push(n);
      break;

      case 2:
      if(deque.empty() && enque.empty())
      {
        cout<<"Queue is Empty"<<endl;
        continue;
      }
      else if(deque.empty())
      {
        while(!enque.empty())
        {
          deque.push(enque.top());
          enque.pop();
        }
        cout<<"Popped Element "<<deque.top()<<endl;
        deque.pop();
      }
      else
      {
        cout<<"Popped Element "<<deque.top()<<endl;
        deque.pop();
      }
      break;
    }
  }
  return 0;
}
