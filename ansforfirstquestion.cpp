#include <bits/stdc++.h>
using namespace std;
int arr[10000];

void init(int n, int Size[])
{
for(int i = 1; i<n; i++)
{
arr[i] = i;
Size[i] = 1;
}
}

int root(int i)
{
//using path compression
while(arr[i]!=i)
{
arr[i] = arr[arr[i]];
i = arr[i];
}
return i;
}

//union with path compression
void weighted_union(int a, int b, int Size[])
{
int root_a = root(a);
int root_b = root(b);
if(root_a==root_b)
return;
if(Size[root_a]<Size[root_b])
{
arr[root_a] = arr[root_b];
Size[root_b] += Size[root_a];
Size[root_a] = 0;
}
else
{
arr[root_b] = arr[root_a];
Size[root_a] += Size[root_b];
Size[root_b] = 0;
}
}

void printAns(int a1[], int n)
{
int a[n+1];
for(int i = 0; i<=n; i++)
{
a[i] = a1[i];
}
sort(a, a+n+1);
for(int it = 1; it<n; it++)
{
if(a[it]>0 && a[it]<1001)
cout<<a[it]<<" ";
}
cout<<endl;
}

int main()
{
int n, m;
cin>>n>>m;
int Size[n+1];
init(n+1, Size);
while(m--)
{
int x, y;
cin>>x>>y;
weighted_union(x, y, Size);
printAns(Size, n+1);
}
return 0;
}