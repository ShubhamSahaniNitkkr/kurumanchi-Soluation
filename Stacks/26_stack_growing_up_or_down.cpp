#include<iostream>
using namespace std;

void checkgrowth(int *temp)
{
  int temp1;
  if(&temp1<temp)
  cout<<"Upward"<<endl;
  else
  cout<<"Downward"<<endl;
  return;
}

int main()
{
  int temprory;
  checkgrowth(&temprory);
}
