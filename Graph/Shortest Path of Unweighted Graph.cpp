#include<iostream>
#include<queue>
using namespace std;

struct node{
  int dest;
  struct node* link;
};

struct list{
  struct node *head;
};

struct graph{
  int v;
  struct list* array;
};

struct graph *creategraph(int v)
{
  struct graph* g=(struct graph *)malloc(sizeof(struct graph));
  g->v=v;
  g->array=(struct list *)malloc( v * sizeof(struct list ));

  for(int i=0;i<v;i++)
  g->array[i].head=NULL;


  return g;
}


struct graph *linknode(struct graph *g,int src,int dest)
{
  struct node *newNode=(struct node *)malloc(sizeof(struct node));
  newNode->dest=dest;

  newNode->link=g->array[src].head;
  g->array[src].head=newNode;

  return g;

}


void Display(struct graph *g)
{
  for(int i=0;i<g->v;i++)
  {
    cout<<"["<<i<<"]";
    struct node *p=g->array[i].head;
    while(p)
    {
      cout<<p->dest;
      p=p->link;
    }
    cout<<endl;
  }
}

queue <int> q;


void BFS_traversal(struct graph *g,int src)
{

  int Distances[g->v];
  for(int i=0;i<g->v;i++)
   Distances[i]=-1;
  Distances[src]=0;

  q.push(src);
  while(!q.empty())
  {
    int s=q.front();
    q.pop();

    for(int i=0;i<g->v;i++)
     if(Distances[i]==-1)
     {
       Distances[i]=Distances[s]+1;
       q.push(i);
     }
  }

  for(int i=0;i<g->v;i++)
  cout<<Distances[i]<<" ";

  return;
}




int main()
{

  struct graph *start=creategraph(5);
  start=linknode(start,0,1);
  start=linknode(start,0,2);
  start=linknode(start,2,1);
  start=linknode(start,2,3);
  start=linknode(start,1,4);
  start=linknode(start,3,4);
  // Display(start);
  BFS_traversal(start,0);




  return 0;
}
