#include<stdio.h>
#include<stdlib.h>


void count_sort(int a[], int n) {

    int max,i,j;
    int b[n];
    max = a[0];
    for(i=0;i<n;i++){
        if(a[i]>max) {
            max=a[i];
        }
    }

    int count[max+1];
    for( i=0;i<=max;i++) {
        count[i] = 0;
    }
    for(i=0;i<n;i++) {
        count[a[i]]++;
    }

    for(i=1;i<max+1;i++){
        count[i]+= count[i-1];
    }
    
    for(i=0;i<n;i++){
        b[count[a[i]]-1] = a[i];
        count[a[i]]--;
    }

    for(i=0;i<n;i++) {
        a[i] = b[i];
    }

}


int main() {
    int i,j,k,n;
    scanf("%d", &n);
    int a[n];
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    count_sort(a,n);
    printf("sorted array is below\n");
    for(i=0;i<n;i++){
        printf("%d\n", a[i]);
    }
}

