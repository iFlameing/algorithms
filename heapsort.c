#include<stdio.h>
#include<stdlib.h>


int main() {
    int i,j,k,n;

    scanf('%d', &n);
    int a[n];
    for(i=0;i<n;i++) {
        scanf('%d', &a[i]);
    }

    build_heap(a,n);
    heap_sort(a,n);

    for(i=0;i<n;i++) {
        printf('%d', a[i]);
    }
}

void build_heap(int a[],n) {
    int i;
    for(i=n/2;i>0;i--) {
        shiftIndexDown(a,i,n);
    }
}

void shiftIndexDown(a, i, n) {
    int l=2*i;
    int max= i;

    if(l<n && a[l]>max) {
        max = l;
    }

    int rightChild = 2*i + 1;
    if(rightChild<n && a[rightChild]>a[max]) {
        max = rightChild;
    }

    if(i != max) {
        int temp = a[i];
        a[i] = a[max];
        a[max] = temp;
        shiftIndexDown(i);
    }
}

void heap_sort(int a[], int n) {
    int i, j, k;

    for(i = n-1;i>0;i--) {
        a[i] = extractMax(a,i);
    }

}

void extractMax(int a[], int n) {
    int result = a[0];
    a[0] = a[i];
    a[i] = -1000000007;
    shiftIndexDown(0);
}