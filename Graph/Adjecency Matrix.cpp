#include<iostream>
using namespace std;


void adj_matrix()
{

  int V,E;
  string u,v;
  cout<<"No. of Vertices & No. of Edges"<<endl;
  cin>>V>>E;
  string nodes[V];
  cout<<"Enter names of nodes"<<endl;
  for(int i=0;i<V;i++)
  cin>>nodes[i];

  int adj[V][V];
  for(int i=0;i<V;i++)
    for(int j=0;j<V;j++)
      adj[i][j]=0;


    for(int i=0;i<E;i++)
    {
      cin>>u>>v;
      int start,end;

      for(int i=0;i<V;i++)
      {
        if(nodes[i]==u)
        {
          start=i;
          break;
        }
      }

      for(int i=0;i<V;i++)
      {
        if(nodes[i]==v)
        {
          end=i;
          break;
        }
      }

      adj[start][end]=1;
      //for undirected graph
      // adj[v][u]=1;
    }

    for(int i=0;i<V;i++)
    {
      for(int j=0;j<V;j++)
        cout<<adj[i][j]<<'\t';
      cout<<endl;
    }

  return;
}

int main()
{
  int choice;
  while(1)
  {
    cout<<"1.Adjecency Matrix ?"<<endl;
    cout<<"2. Exit ?"<<endl;
    cin>>choice;
    switch (choice) {
      case 1:
      adj_matrix();
      break;
      case 2:
      exit(1);
    }
  }
  return 0;
}
