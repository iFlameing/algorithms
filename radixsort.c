#include<stdio.h>
#include<stdlib.h>

int main() {

    int i, j, k, n;
    scanf("%d", &n);
    int a[n];
    for(i=0;i<n;i++) {
        scanf("%d", &a[i]);
    }
    radix_sort(a,n);
    for(i=0;i<n;i++) {
        printf("%d", a[i]);
    }
}

void radix_sort(int a[], int n) {
    int max, i,j,max_number, digits=0;
    max = a[0];
    for(i=0;i<n;i++) {
        if(a[i]>max) {
            max = a[i];
        }
    }
    max_number = max;
    while(max>0) {
        max = max/10;
        digits++;
    }
    for(i=0;i<digits;i++) {
        count_sort(a,n,i, max_number);
    }
}

void count_sort(int a[], int n, int place, int max_number) {
    int range = 10;
    int i,j,n;
    int count[range];
    int output[n];

    for(i=0;i<n;i++) {
        count[(a[i]/pow(10,place))%range]++;
    }

    for(i=1;i<n;i++) {
        count[i]+=count[i-1]
    }

    for(i=0;i<n;i++) {
        output[count[(a[i]/pow(10,place))%range]-1] = a[i];
        count[(a[i]/pow(10,place))%range]--;
    }

    for(i=0;i<n;i++) {
        a[i] = output[i];
    }
}