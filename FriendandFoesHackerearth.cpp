#include<bits/stdc++.h>
using namespace std;

void makesets(vector<int> &parent, vector<int> &rank, numOfFriends){
    for(int i=1;i<=numOfFriends;++i){
        parent.push_back(i);
        rank.push_back(1);
    }
}

int Find(vector<int> parent, int node){
    while(parent[node] != node){
        node = parent[node];
    }
    return node;
}

void Union(vector<int> parent, vector<int> rank, int node1, int node2){
    node1 = Find(parent,node1);
    node2 = Find(parent, node2);
    if(node1 == node2){
        return 0;
    }
    if(rank[node1]> rank[node2]){
        parent[node2] = node1;
        rank[node1]++;
    } else {
        parent[node1] = node2;
        rank[node2]++;
    }
}

void Enemy(vector<int> parent, vector<int> rank, int node1, int node2){
    node1 = Find(node1);
    node2 = Find(node2);
    if(node1 == node2){
        rank[node1] = 0; 
    }
}

int SpecialGroup(vector<int> rank){
    int max =0;
    for(int i=0;i<rank.size();++i){
        if(max<rank[i]){
            max = rank[i];
        }
    }
    return max;
}




int main(){
    ios:base::sync_with-stdio(false);
    cin.tie(0);
    int numOfFriends;
    cin>> numOfFriends;
    vector<int> parent;
    vector<int> rank;

    sets = makesets(parent, rank, numOfFriends);
    return 0;
}