#include<bits/stdc++.h>
using namespace std;

void intialiseVector(vector<int> &vect, int nodes){
    for(int i=1;i<=nodes;++i){
        vect.push_back(i);
    }    
}

void unionCustom(vector<int> &vect, int A, int B){
       int TEMP = vect[ A ];
    for(int i = 1; i < vect.size();i++)
        {
        if(vect[ i ] == TEMP)
        vect[ i ] = vect[ B ]; 
        }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int nodes, edges;
    cin>>nodes;
    vector<int> vect;
    vect.push_back(0);
    intialiseVector(vect,nodes);
    cin>>edges;
    for(int i=1;i<=edges;i++){
        int node1, node2;
        int count=0;
        cin>>node1;
        cin>>node2;
        vector<int> temp;
        unionCustom(vect, node1, node2);
        for(int k=1;k<=nodes;k++){
            for(int l=0;l<vect.size();l++){
                if(vect[l]==k){
                    count++;
                }
            }
            if(count){
                temp.push_back(count);
            }
            count=0;
        }
        sort(temp.begin(), temp.end());
        for(int k=0;k<temp.size();k++){
            cout<<temp[k]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
