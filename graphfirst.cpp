list<int> *adj;
int NumberOfRoad;

vector<string> split_string(string);

int Utils(int v, vector<int> &visited) {
    visited[v] = 1;
    for(auto i = adj[v].begin(); i != adj[v].end(); ++i){
        if(visited[*i]==0){
            NumberOfRoad++;
            Utils(*i,visited);
        }
    }
    return NumberOfRoad;
}

// Complete the roadsAndLibraries function below.
long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities) {
    if(c_lib<=c_road){
        return c_lib*n;
    }
  adj = new list<int>[n+1];
  for(int i=0;i<cities.size();i++){
      adj[cities[i][0]].push_back(cities[i][1]);
      adj[cities[i][1]].push_back(cities[i][0]);
  }
  int NumberOfLibrary = 0;
  NumberOfRoad = 0;
  long int result;
  vector<int> v(n+1,0);
  for(int i=1;i<n+1;i++){
      if(v[i] == 0){
          NumberOfLibrary++;
          Utils(i,v);
      }
  }
  result = NumberOfLibrary*c_lib + NumberOfRoad * c_road;
  return result;
}

10
96295 12709 90581 83503
78455 13046
80408 12229
21285 87954
29676 9393
26819 18141
95610 92204
93185 92915
93464 69895
10580 92171
76854 77064
461 13664
10830 88182
84589 76286
63145 48501
3439 34791
20408 89940
65360 38397
71321 71561