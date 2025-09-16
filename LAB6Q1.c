#include <stdio.h>

void swap(int *a,int *b){
    int t=*a;
    *a=*b;
    *b=t;
}

int partition(int arr[],int low,int high){
    int pivot=arr[high],i=low;
    for(int j=low;j<high;j++){
        if(arr[j]<pivot){swap(&arr[i],&arr[j]);i++;}
    }
    swap(&arr[i],&arr[high]);
    return i;
}

void quicksort(int arr[],int low,int high){
    if(low<high){
        int pi=partition(arr,low,high);
        quicksort(arr,low,pi-1);
        quicksort(arr,pi+1,high);
    }
}

int main(){
    int n; scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    quicksort(arr,0,n-1);
    for(int i=0;i<n;i++) printf("%d ",arr[i]);
    return 0;
}
