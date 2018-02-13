#include<iostream>
#include<stack>
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

  int n;

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
      cout<<"->"<<p->dest;
      p=p->link;
    }
    cout<<endl;
  }
}

stack <int> s;

void Topological_sort(struct graph *g,int v,int visited[])
{
  visited[v]=1;


    for(int i=0;i<g->v;i++)
      if(!visited[i])
      Topological_sort(g,i,visited);

    s.push(v);

  return;
}


void Top_sort(struct graph *g)
{
  int visited[g->v];
  for(int i=0;i<g->v;i++)
   visited[i]=0;

   for(int i=0;i<g->v;i++)
     if(!visited[i])
     Topological_sort(g,i,visited);

   while(!s.empty())
   {
     cout<<" -> "<<s.top()<<" ";
     s.pop();
   }
   return;
}


int main()
{

  struct graph *start=creategraph(4);
  start=linknode(start,0,1);
  start=linknode(start,0,3);
  start=linknode(start,1,2);
  start=linknode(start,2,3);

  Display(start);

  Top_sort(start);




  return 0;
}
