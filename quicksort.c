#include<stdio.h>
#include<stdlib.h>

int partition(int a[], int left, int right) {
    int pivot = a[left];
    int i = left;
    int j = right;
    int temp;
    do {

        do
        {
            i++;
        } while (pivot>a[i] && i<right);
        
        do
        {
            j--;
        } while (a[j]>pivot);

        if(i<j) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
        

    }while(i<j);

    a[left] = a[j];
    a[j] = pivot;

    return j;
}

void quick_sort(int a[], int left, int right) {
    int j;
    if(left<right) {
        j= partition(a,left,right);
        quick_sort(a,left,j);
        quick_sort(a,j+1,right);
    }
}

int main() {
    int i,j,k,n;

    scanf("%d", &n);
    int a[n];
    for(i=0;i<n;i++) {
        scanf("%d", &a[i]);
    }

    quick_sort(a,0,n);
    printf("Array after sorted");
    for(i=0;i<n;i++) {
        printf("%d", a[i]);
    }
}
