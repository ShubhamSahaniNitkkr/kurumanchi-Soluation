#include<iostream>
using namespace std;

struct node{
  int dest;
  int weight;
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


struct graph *linknode(struct graph *g,int src,int n,int dest)
{
  struct node *newNode=(struct node *)malloc(sizeof(struct node));
  newNode->weight=n;
  newNode->dest=dest;

  newNode->link=g->array[src].head;
  g->array[src].head=newNode;

  return g;

}

int findweight(struct graph *g,int src,int dest)
{
  int weight=-1;

  struct node *p=g->array[src].head;
  while(p)
  {
    if(p->dest==dest)
    {
      weight=p->weight;
      break;
    }
    p=p->link;
  }

  return weight;
}


void Display(struct graph *g)
{
  for(int i=0;i<g->v;i++)
  {
    cout<<"["<<i<<"]";
    struct node *p=g->array[i].head;
    while(p)
    {
      cout<<"->{"<<p->weight<<"}"<<p->dest;
      p=p->link;
    }
    cout<<endl;
  }
}



void print(struct graph *g,int Distance[])
{
  cout<<"Vertex"<<'\t'<<"Total Weight"<<endl;
  for(int i=0;i<g->v;i++)
    cout<<i<<'\t'<<Distance[i]<<endl;

  return;
}


int mindistance(struct graph *g,int Distance[],int visited[])
{
  int min_index,min=100;

  for(int i=0;i<g->v;i++)
  {
    if(!visited[i] && Distance[i]<=min)
    {
      min_index=i;
      min=Distance[i];
    }
  }
  return min_index;
}

void PrintD(struct graph *g,int Distance[])
{
  for(int i=0;i<g->v;i++)
  cout<<Distance[i]<<" ";
  cout<<endl;
}


void Dijkstra(struct graph *g,int src)
{
    int weight,Distance[g->v];
    int visited[g->v];

    for(int i=0;i<g->v;i++)
    {
      visited[i]=0;
      Distance[i]=100;
    }
    Distance[src]=0;


   for(int i=0;i<g->v;i++)
   {
     int u=mindistance(g,Distance,visited);
     visited[u]=1;

     for(int i=0;i<g->v;i++)
     {
       if(!visited[i] && Distance[u]!=100)
       {
         weight=findweight(g,u,i);
         if(weight!=-1 && Distance[i]>Distance[u]+weight)
           Distance[i]=Distance[u]+weight;
       }
     }
   }
   print(g,Distance);
   return;
}


int main()
{

  struct graph *start=creategraph(5);
  start=linknode(start,0,4,1);
  start=linknode(start,0,1,2);
  start=linknode(start,2,2,1);
  start=linknode(start,2,4,3);
  start=linknode(start,1,4,4);
  start=linknode(start,3,4,4);
  // Display(start);
  Dijkstra(start,0);




  return 0;
}
