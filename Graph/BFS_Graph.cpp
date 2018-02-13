#include<iostream>
#include<queue>
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

queue <int> q;

void BFS_traversal(struct graph *g,int v)
{
  cout<<"BFS Traversal"<<endl;

  int visited[g->v];
  for(int i=0;i<g->v;i++)
   visited[i]=0;

   visited[v]=1;
   q.push(v);

   while(!q.empty())
   {
      int s=q.front();
      cout<<s<<" ";
      q.pop();

      for(int i=0;i<g->v;i++)
       if(!visited[i])
       {
         visited[i]=1;
         q.push(i);
       }
   }
  return;
}



int main()
{
  struct graph *g=Create(4);

   g=linking(g,0,1);
   g=linking(g,0,2);
   g=linking(g,1,2);
   g=linking(g,2,0);
   g=linking(g,2,3);
   g=linking(g,3,3);
  // start=linking(start,0,1);
  // start=linking(start,0,3);
  // start=linking(start,1,2);
  // start=linking(start,2,0);
  // start=linking(start,2,3);
  BFS_traversal(g,2);
  return 0;
}
