#include<bits/stdc++.h>
using namespace std;
// This is my own implementation of graph when I learned it from the geeks for geeks the implementation
// are same the function name are same just because I am currently practising this and dip dive into it.

class Graph {
  int v;
  list<int>* adj;
  void DFSUtil(int v, bool visited[] );
  public:
  Graph(int V);
  void addEdge(int v, int w);
  void DFS();
};

Graph:: Graph(int V){
  this->v = V;
  adj = new list<int>[V];
};

void Graph::addEdge(int v, int w){
  adj[v].push_back(w);
  adj[w].push_back(v);
}

void Graph::DFSUtil(int v, bool visited[]){
  visited[v] = true;
  cout<<v<<endl;
  for(auto i = adj[v].begin(); i!=adj[v].end();++i){
    if(!visited[*i])
      DFSUtil(*i, visited);
  }
};


void Graph::DFS(){
  bool visited[v];
  for(int i=0;i<v;i++) {
    visited[i] = false;
  }

  for(int i=0;i<v;i++){
    if(!visited[i])
    DFSUtil(i,visited);
  }
}



int main() {
    Graph g(4); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 
  
    cout << "Following is Depth First Traversaln"; 
    g.DFS(); 


  return 0;
}