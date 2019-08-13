#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> iPair;

class disJoint {
  int *parent, *rank;
  int n ;
  public: // this is the  size of array of parrent and rank
    disJoint(int n);
    int find(int u);
    void Union(int u, int v);

};

disJoint::disJoint(int N) {
  this -> n = N;
  parent = new int[n+1];
  rank = new int[n+1];
  for(int i=0;i<=n;i++) {
    parent[i] = i;
    rank[i] = 0;
  }
}
// find the root of the given vertex and do the path compression
int disJoint::find(int u) {
  if(parent[u]!=u) {
    parent[u] = find(parent[u]);
  }
  return parent[u];
}

void disJoint::Union(int u, int v) {
  int x = find(u); int y = find(v);
  if(rank[x]>rank[y]) {
    parent[y] = x;
  }
  else if(rank[x]<rank[y]) {
    parent[x] = y;
  }
  else {
    parent[x] = y;
    rank[y]++;
  }
}
class kruskal {
  int v, e;
  vector<pair<int, pair<int, int> > > edge;
  public:
  kruskal(int v, int e);
  void addEdge(int u, int v, int w);
  int kruskalmst();
};

kruskal::kruskal(int V, int E) {
  this -> v = V;
  this -> e = E;
}

void kruskal::addEdge(int u,int v, int w) {
  edge.push_back({w,{u,v}});
}

int kruskal::kruskalmst() {
  int mst_wt = 0;
  sort(edge.begin(), edge.end());
  disJoint ds(v);
  for(auto it= edge.begin();it!=edge.end();++it) {
    int u = ds.find(it->second.first);
    int v = ds.find(it->second.second);
    if(u!=v) {
      cout << u << " - " << v << endl;
      mst_wt += it->first;
      ds.Union(u, v);
    }
  }
  return mst_wt;
}

int main() {
  int V = 9 , E =14;
  kruskal g(V, E);
  	// making above shown graph 
	g.addEdge(0, 1, 4); 
	g.addEdge(0, 7, 8); 
	g.addEdge(1, 2, 8); 
	g.addEdge(1, 7, 11); 
	g.addEdge(2, 3, 7); 
	g.addEdge(2, 8, 2); 
	g.addEdge(2, 5, 4); 
	g.addEdge(3, 4, 9); 
	g.addEdge(3, 5, 14); 
	g.addEdge(4, 5, 10); 
	g.addEdge(5, 6, 2); 
	g.addEdge(6, 7, 1); 
	g.addEdge(6, 8, 6); 
	g.addEdge(7, 8, 7); 

	cout << "Edges of MST are \n"; 
	int mst_wt = g.kruskalmst(); 

	cout << "\nWeight of MST is " << mst_wt; 

	return 0;
}