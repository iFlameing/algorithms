#include<bits/stdc++.h>
using namespace std;
define long long int;
vector<int> tree;
vector<int> A;

void build(int node, int start, int end){
    if(start == end){
        tree[node] = A[start];
    } else {
        int mid = (start + end)/2;
        build(2*node,start, mid);
        build(2*node+1,mid+1,end);
        tree[node] = std::min(tree[2*node], tree[2*node+1]);
    }
}

void update(int node, int start, int end, int idx, int val){
    if(start == end){
        A[idx]=val;
        tree[node]=val;
    } else {
        int mid = (start + end) / 2;
        if(idx<=end && idx>=start){
            update(node, start, mid, idx, val);
        } else {
            update(node, mid+1, end, idx, val);
        }
        tree[node] = std::min(tree[2*node] , tree[2*node+1]);
    }
    
}

int query(int node, int start, int end, int l, int r){
    if(r < start or end < l){
        return 0;
    }
    else if(start>=l and end<=r){
        return tree[node];
    }

    int mid = (start + end) /2;
    int p1 = query(2*node, start, mid, l, r);
    int p2 = query(2*node+1, mid+1, end, l,r);
    if(p1==0) {
        return p2;
    }
    if(p2==0) {
        return p1;
    }
    return std::min(p1,p2);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,q;
    cin>>n;
    cin>>q;
    tree.clear();
    A.clear();
    A.resize(n);
    tree.resize(2*n+1,-1);
    for(int i=0;i<n;++i){
        int temp;
        cin>>temp;
        A[i] = temp;
    }
    build(1,0,n-1);
    for(int i=0;i<=2*n+1;++i){
        cout<<tree[i]<<" ";
    }
    cout<<"\n";
    int l,r;
    string ch;
    for(int i=0;i<q;++i){
        cin>>ch;
        cin>>l;
        cin>>r;
        if(ch.compare("q")==0){
            int result = query(1,0,n-1,l-1,r-1);
            cout<<result<<"\n";

        } else {
            update(1,0,n-1,l-1,r-1);
        }


    }


    return 0;
}