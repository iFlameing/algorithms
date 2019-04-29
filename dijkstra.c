#include<stdio.h>
#include<stdlib.h>

#define infinity 100000007

int vertex;

int mindist(int dist[], int mstSet[]) {
    int min = infinity;
    int minIndex,i;

    for(i=0;i<vertex;i++) {
        if(!mstSet[i] && dist[i]<min) {
            min = dist[i];
            minIndex = i;
        }
    }

    return minIndex;
}

void dijkstra(int graph[vertex][vertex], int src) {

    int dist[vertex];
    int mstSet[vertex];
    int i,j;
    for(i=0;i<vertex;i++) {
        dist[i] = infinity;
        mstSet[i] = 0;
    }

    dist[src] = 0;

    for(i=0;i<vertex-1;i++) {
        int u = mindist(dist, mstSet);
        mstSet[u] =1;

        for(j=0;j<vertex;j++) {
            if(graph[u][j] && !mstSet[j] && dist[u]+graph[u][j]<dist[j]){
                dist[j] = dist[u] + graph[u][j];
            }

        }
    }

    for( i = 0; i < vertex; i++)
    {
        printf("%d - %d\n", i, dist[i]);
    }
    
}

int main() {
int edge, i, j, source, connectedNode, cost,src;
printf("enter the vertex\n");
scanf("%d",&vertex);
int graph[vertex][vertex];

for(i=0;i<vertex;i++) {
    for(j=0;j<vertex;j++) {
        graph[i][j] = 0;
    }
}

printf("enter the no of edge\n");
scanf("%d", &edge);

for(i=0;i<edge;i++){
    printf("enter the value of source and connectedNode\n");
    scanf("%d%d", &source,&connectedNode);
    printf("enter the cost for visiting connected node\n");
    scanf("%d", &cost); 
    graph[source][connectedNode] = cost;
    graph[connectedNode][source] = cost;
}
printf("Enter the source node\n");
scanf("%d",&src);

dijkstra(graph,src);
return 0;
}