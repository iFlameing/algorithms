#include<bits/stdc++.h>
using namespace std;

void makesets(vector<int> &parent, vector<int> &rank, int numOfFriends){
    for(int i=1;i<=numOfFriends;++i){
        parent.push_back(i);
        rank.push_back(1);
    }
}

int Find(vector<int> &parent, int node){
    while(parent[node] != node){
        parent[node] = parent[parent[node]];
        node = parent[node];
    }
    return node;
}

void Union(vector<int> &parent, vector<int> &rank, int node1, int node2){
    node1 = Find(parent,node1);
    node2 = Find(parent, node2);
    if(node1 == node2){
        return;
    }
    if(rank[node1]> rank[node2]){
        parent[node2] = node1;
        rank[node1] = rank[node1] + rank[node2];
        rank[node2] = 0;
    } else {
        parent[node1] = node2;
        rank[node2] += rank[node1];
        rank[node1]=0;
        
    }
}

void Enemy(vector<int> &parent, vector<int> &rank, int node1, int node2){
    node1 = Find(parent,node1);
    node2 = Find(parent,node2);
    if(node1 == node2){
        rank[node1] = 0; 
    }
}

int SpecialGroup(vector<int> &rank){
    int max =0;
    for(int i=1;i<rank.size();++i){
        if(max<rank[i]){
            max = rank[i];
        }
    }
    return max;
}




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int classmates, numberOfFriends;
    cin>> classmates;
    vector<int> parent;
    parent.push_back(0);
    vector<int> rank;
    rank.push_back(0);

    makesets(parent, rank, classmates);
    cin>>numberOfFriends;
    for(int i=0;i<numberOfFriends;++i){
        int node1,node2;
        cin>>node1;
        cin>>node2;
        Union(parent, rank, node1, node2);
    }
    int numberOfEnemy;
    cin>>numberOfEnemy;
    for(int i=0;i<numberOfEnemy;++i){
        int node1, node2;
        cin>>node1;
        cin>> node2;
        Enemy(parent, rank, node1, node2);
    }

    int result = SpecialGroup(rank);
    cout<<result;
    return 0;
}