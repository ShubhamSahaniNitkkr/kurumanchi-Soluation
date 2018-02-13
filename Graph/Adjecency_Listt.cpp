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

  //if graph is undirected
  // struct node *newNode1=(struct node *)malloc(sizeof(struct node));
  // newNode1->dest=src;
  // newNode1->link=g->array[dest].head;
  // g->array[dest].head=newNode1;

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
      cout<<"->{"<<p->weight<<"}"<<p->dest;
      p=p->link;
    }
    cout<<endl;
  }
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
  Display(start);

  return 0;
}
