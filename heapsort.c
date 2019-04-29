#include<stdio.h>
#include<stdlib.h>

void shiftIndexDown(int a[], int i, int n) {
    int l=2*i;
    int max= i;

    if(l<n && a[l]>a[max]) {
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
        shiftIndexDown(a, max, n);
    }
}

int extractMax(int a[], int n) {
    int result = a[0];
    a[0] = a[n];
    shiftIndexDown(a,0,n);
    return result;
}

void build_heap(int a[], int n) {
    int i;
    for(i=n/2;i>=0;i--) {
        shiftIndexDown(a,i,n);
    }
}



void heap_sort(int a[], int n) {
    int i, j, k;

    for(i = n-1;i>0;i--) {
        a[i] = extractMax(a,i);
    }

}



int main() {
    int i,j,k,n;

    printf("enter the size of heap array\n"); 

    scanf("%d", &n);

    int a[n];
    for(i=0;i<n;i++) {
        scanf("%d", &a[i]);
    }

    build_heap(a,n);

    printf("heap formed array\n");

    for(i=0;i<n;i++) {
        printf("%d\t", a[i]);
    }

    printf("\n");

    heap_sort(a,n);
    printf("Array after sorted\n");
    for(i=0;i<n;i++) {
        printf("%d\t", a[i]);
    }
}

