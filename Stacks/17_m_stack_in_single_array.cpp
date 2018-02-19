#include<iostream>
using namespace std;

class kstack{
  int *arr,*next,*top,n,k,free;
public:
  kstack(int n,int k);
  void push(int item,int sn);
  int pop(int sn);
  int isFull(){return (free == -1);}
  int isEmpty(int sn){return (top[sn] == -1);}
};

kstack :: kstack(int k,int n)
{
  arr= new int[n];
  next= new int[n];
  top= new int[k];

  for(int i=0;i<k;i++)
   top[i]=-1;

   free=0;

   for(int i=0;i<n-1;i++)
     next[i]=i+1;
    next[n-1]=-1;

}

void kstack :: push(int item,int sn)
{
  if(isFull())
  {
    cout<<"Overflow"<<endl;
    return;
  }
  int i=free;
  free=next[i];
  next[i]=top[sn];
  top[sn]=i;
  arr[i]=item;

}


int kstack ::pop(int sn)
{
  if(isEmpty(sn))
  {
    cout<<"Stack Underflow"<<endl;
    return INT_MAX;
  }
  int i=top[sn];
  top[sn]=next[i];
  next[i]=free;
  free=i;
  return arr[i];
}

int main()
{
    int k = 3, n = 10;
    kstack ks(k, n);

    ks.push(15, 2);
    ks.push(45, 2);

    ks.push(17, 1);
    ks.push(49, 1);
    ks.push(39, 1);

    ks.push(11, 0);
    ks.push(9, 0);
    ks.push(7, 0);

    cout << "Popped element from stack 2 is " << ks.pop(2) << endl;
    cout << "Popped element from stack 1 is " << ks.pop(1) << endl;
    cout << "Popped element from stack 1 is " << ks.pop(1) << endl;
    cout << "Popped element from stack 1 is " << ks.pop(1) << endl;


    cout << "Popped element from stack 0 is " << ks.pop(0) << endl;

    return 0;
}
