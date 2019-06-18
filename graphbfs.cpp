#include<bits/stdc++.h>
using namespace std;

class Graph{
  int v;
  list<int>* adj;
  public:
  Graph(int v);
  void addEdge(int v, int w);
  void BFS(int s);
};

Graph::Graph(int V) {
  this -> v = V;
  adj = new list<int> [v];
}

void Graph::addEdge(int v, int w){
  adj[v].push_back(w);
  adj[w].push_back(v);
}

void Graph::BFS(int s){
  bool visited[v];
  for(int i=0;i<v;i++){
    visited[i] = false;
  }
  visited[s] = true;
  list<int> queue;
  queue.push_back(s);
  while (!queue.empty()){
    s= queue.front();
    cout<<s<<endl;
    queue.pop_front();
    for(auto i=  adj[s].begin(); i!=adj[s].end();i++){
      if(!visited[*i]){
        visited[*i] = true;
        queue.push_back(*i);
      }
    }
  }
}

int main(){

    // Create a graph given in the above diagram 
    Graph g(4); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 
  
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n"; 
    g.BFS(2); 

  return 0;
}