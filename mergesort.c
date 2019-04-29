#include<stdio.h>
#include<stdlib.h>

void merge(int a[], int left, int mid, int right){
    printf("this is mid in merge %d%d%d\n",left, mid , right);
    int i,j,k,left_end,right_end,mid_end;
    k=0;
    left_end = left;
    right_end = right;
    mid_end = mid+1;
    int temp[100];

    while(left<=mid && mid_end<=right){
        if(a[left]<a[mid_end]){
            temp[k] = a[left];
            k++;
            left++;
        }
        else {
            temp[k] = a[mid_end];
            mid_end++;
            k++;
        }
    }

    while(left<=mid) {
        temp[k] = a[left];
        left++;
        k++;
    }

    while(mid_end<=right_end) {
        temp[k] = a[mid_end];
        mid_end++;
        k++;
    }
    
    for(i=0;i<k;i++){
        a[left_end] = temp[i];
        left_end++;
    }
}


void merge_sort(int a[], int left, int right){
    int mid;
    if(left<right){
        mid = (left+right)/2;
        merge_sort(a,left,mid);
        merge_sort(a,mid+1,right);
        merge(a,left,mid,right);
    }
}

int main() {

    int i, j, k, n;
    printf("enter the size of array\n");
    scanf("%d", &n);
    int a[n];
    for(i=0;i<n;i++) {
        scanf("%d", &a[i]);
    }
    merge_sort(a,0,n-1);
    printf("array after sorted\n");
    for(i=0;i<n;i++){
        printf("%d",a[i]);
    }
}
