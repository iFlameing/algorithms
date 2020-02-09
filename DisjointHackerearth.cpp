#include<bits/stdc++.h>

vector<int> intialiseVector(vector<int> &vect, int nodes){
    for(int i=1;i<=nodes;++i){
        vect.push_back(i);
    }    
    return vect;
}

vector<int> union(vector<int> &vect, int node1, int node2){
    
    if(node1<node2){
        min = node1;
    } else {
        min = node2;
    }
    for(int i=1;i<=vect.size();++i) {
        if(vect[i]= node1 || vect[i] = node2){
            vect[i] = min;
        }
    }
}


int main(){
    ios:base::sync_with_stdio(false);
    cin.tie(0);
    int nodes, edges;
    cin>>nodes;
    vector<int> vect;
    vect=intialiseVector(vect);
    cin>>edges;
    for(int i=1;i<=edges;i++){
        int node1, node2;
        int count=0;
        cin>>node1;
        cin>>node2;
        vect = union(vect, node1, node2);
        for(int j=nodes; j>0; --j){
            for(int k=1;k<=nodes;++k){
                if(j==vect[k]){
                    count++;
                }
            }
            
            cout<<count<<" ";
            count=0;
        }
        cout<<"\n";
    }
    return 0;
}
