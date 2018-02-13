#include<iostream>
#include<stack>
using namespace std;

struct node{
  int data;
  struct node *link;
};

struct list{
  struct node *head;
};

struct graph{
  int v;
  struct list *array;
};


struct graph *Create(int v)
{
  struct graph *g=(struct graph *)malloc(sizeof(struct graph));
  g->v=v;
  g->array=(struct list *)malloc(v * sizeof(struct list));

  for(int i=0;i<v;i++)
  g->array[i].head=NULL;

  return g;

}


struct graph *linking(struct graph *g,int src,int dest)
{
  struct node *temp=(struct node *)malloc(sizeof(struct node));
  temp->data=dest;
  temp->link=g->array[src].head;
  g->array[src].head=temp;

  struct node *temp1=(struct node *)malloc(sizeof(struct node));
  temp1->data=src;
  temp1->link=g->array[dest].head;
  g->array[dest].head=temp1;

  return g;
}




void DFS(struct graph *g,int u,int Visited[])
{
  Visited[u]=1;
  cout<<u<<" ";

  for(int i=0;i<g->v;i++)
   if(!Visited[i])
    DFS(g,i,Visited);
  return;
}

void DFS_traversal(struct graph *g,int v)
{
  cout<<"DFS Traversal"<<endl;
  int Visited[g->v];
  for(int i=0;i<g->v;i++)
   Visited[i]=0;

    DFS(g,v,Visited);

  return;
}



int main()
{
  struct graph *start=Create(4);
  start=linking(start,0,1);
  start=linking(start,0,3);
  start=linking(start,1,2);
  start=linking(start,2,0);
  start=linking(start,2,3);
  DFS_traversal(start,2);
  return 0;
}
