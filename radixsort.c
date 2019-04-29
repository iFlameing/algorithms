#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void count_sort(int a[], int n, int place) {
    int range = 10;
    int i,j;
    int count[range];
    int output[n];
    int divide = pow(10,place);
    for(i=0;i<range;i++) {
        count[i] = 0;
    }

    for(i=0;i<n;i++) {
        count[(a[i] / divide ) % range]++;
    }


    for(i=1;i<range;i++) {
        count[i]+=count[i-1];
    }



    for(i=0;i<n;i++) {
        output[count[(a[i]/divide)%range]-1] = a[i];
        count[(a[i]/divide)%range]--;
    }

    for(i=0;i<n;i++) {
        a[i] = output[i];
    }
}

void radix_sort(int a[], int n) {
    int max, i,j;
    int digits = 0;
    max = a[0];
    for(i=0;i<n;i++) {
        if(a[i]>max) {
            max = a[i];
        }
    }

    while ( max>0) {
        max = max/10;
        digits++;
    }

    for(i=0;i<digits;i++) {
        count_sort(a,n,i);
    }
}



int main() {

    int i, j, k, n;
    printf("enter the size of array");
    scanf("%d", &n);

    int a[n];

    for(i=0;i<n;i++) {
        scanf("%d", &a[i]);
    }

    radix_sort(a,n);

    printf("Sorted array below");

    for(i=0;i<n;i++) {
        printf("%d", a[i]);
    }
}



