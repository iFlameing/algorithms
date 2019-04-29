#include<stdio.h>
#include<stdlib.h>

#define infinity 100000007

int vertex;
int minCost(int key[], int mstSet[]) {
    int min = infinity;
    int minIndex,i;

    for(i=0;i<vertex;i++) {
        if(!mstSet[i] && key[i]<min) {
            min = key[i];
            minIndex = i;
        }
    }

    return minIndex;
}

void prims(int graph[vertex][vertex]){
    int i,j;
    int key[vertex];
    int parent[vertex];
    int mstSet[vertex];

    for(i=0;i<vertex;i++) {
        key[i] = infinity;
        mstSet[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    for(i=0;i<vertex-1;i++) {

        int u = minCost(key, mstSet);
        mstSet[u] = 1;

        for(j=0;j<vertex;j++) {
            if( graph[u][j] && !mstSet[j] && graph[u][j]<key[j]){
                key[j] = graph[u][j];
                parent[j] = u;
            }
        }
        printf("\n");
    }

    for( i=1; i<vertex; i++) {
        printf("%d - %d\t %d\n",parent[i],i,graph[i][parent[i]]);
    }
}

int main() {
int edge, i, j, source, connectedNode, cost;
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

prims(graph);
return 0;
}