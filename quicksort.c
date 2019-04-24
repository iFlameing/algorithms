#include<stdio.h>
#include<stdlib.h>

int main() {
    int i,j,k,n;

    scanf('%d', &n);
    int a[n];
    for(i=0;i<n;i++) {
        scanf('%d', &a[i]);
    }

    quick_sort(a,0,n)

    for(i=0;i<n;i++) {
        printf('%d', a[i]);
    }
}

void quick_sort(int a[], int left, int right) {
    int j;
    if(left<right) {
        j= partition(left);
        quick_sort(a,left,j);
        quick_sort(a,j+1,right)
    }
}

void partition(int a[], int left, int right) {
    int pivot a[left];
    int i = left;
    int j = right;
    int temp;

    do {

        do {
            i++;
        }while(i<right && a[i]<pivot)

        do {
            j--
        }while(a[j]>pivot && j>left)
        if(i<j) {
            int temp = a[j];
            a[j] = a[i];
            a[i] = temp;
        }
    }while(left<right)
    temp =a[left];
    a[left] = a[j];
    a[j] = temp;
    
    return j;
}