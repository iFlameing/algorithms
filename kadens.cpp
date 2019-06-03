#include<bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int> a, int length){
    int max_so_far =a[0]; int max_ending_so_far=a[0];
    for(int i=1; i<length; i++) {
        max_ending_so_far = max(a[i], max_ending_so_far + a[i]);
        max_so_far = max(max_so_far, max_ending_so_far);
    }
    return max_so_far;
}

int main(){
    vector<int>v;
    int length;
    cout<<"enter the length of array\n";
    cin>>length;
    int c;
    for(int i=0;i<length;i++){
        cin>>c;
        v.push_back(c);
    }
    int result = maxSubArray(v,length);
    cout<<"The max sum of subarray is"<<result;
    return 0;
}