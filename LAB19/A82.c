#include<stdio.h>
#include<stdlib.h>

#define max 100;

struct Node
{
    /* data */
    int vertex;
    struct Node * link;
};

struct Graph
{
    /* data */
    int numvertex;
    struct Graph ** adjLists;
    int * visited;
};

struct Node * createNode(int v){
    struct Node * newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->link = NULL;
    return newNode;
}
    
struct Graph *  createGraph(int vertices){
    struct Graph * graph = (struct Node *)malloc(sizeof(struct Graph));
    graph->numvertex = vertices;
    graph->visited = (int *)malloc(vertices * sizeof(int));
    graph->adjLists = (struct Node *)malloc(vertices * sizeof(struct Graph));


    for(int i=0;i<vertices;i++){
        graph->adjLists[i] = NULL;

        graph->visited[i] = 0;
    
    }
    return graph;

}

void addEdge(struct Graph * graph,int src,int dest){
    struct Node * newNode = createNode(dest);
    newNode->link = graph ->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->link = graph ->adjLists[dest];
    graph->adjLists[dest] = newNode;

}

void DFS(struct Graph * graph,int vertex){
    struct Node * adjList = graph->adjLists[vertex];
    struct Node * temp = adjList;

    graph->visited[vertex] = 1;
    printf("Visited %d \n",vertex);

    while(temp != NULL){
        int connectedVertex = temp->vertex;

        if(graph->visited[connectedVertex] == 0){
            DFS(graph,connectedVertex);
        }
        temp = temp->link;
    }
}
void printGraph(struct Graph * graph){
    for(int v=0;v<graph->numvertex;v++){
        struct Node * temp = graph->adjLists[v];
        printf("\n Adjacency list of vertex %d\n head ",v);
        while(temp){
            printf("-> %d",temp->vertex);
            temp = temp->link;
        }
        printf("\n");
    }
}


void main(){
    struct Graph * graph = createGraph(4);
    addEdge(graph,0,1);
    addEdge(graph,0,2);
    addEdge(graph,1,2);
    addEdge(graph,2,3);

    DFS(graph,0);
}