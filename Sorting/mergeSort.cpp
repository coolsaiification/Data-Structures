#include <iostream>
using namespace std;

void merge(int * arr, int start, int end, int mid){
    int l = mid-start+1;
    int r = end - mid;
    int left[l], right[r];
    for(int i=0;i<l;i++){
        left[i] = arr[start+i];
    }

    for(int i=0;i<r;i++){
        right[i] = arr[mid +1 +i];
    }

    int i=0,j=0,k=start;

    while(i<l && j<r){
        if(left[i] < right[j]){
            arr[k] = left[i];
            i++;
        }
        else{
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while(i<l){
        arr[k] = left[i];
        i++;
        k++;
    }

    while(j<r){
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(int * arr, int start, int end){
    if(start >= end){
        return;
    }
    int mid = (start+end)/2;

    mergeSort(arr, start, mid);
    mergeSort(arr, mid+1, end);
    merge(arr, start, end, mid);
}

int main() {
    int arr[] = {8,7,6,5,4,3,2};
    int n = 7;
    
    mergeSort(arr,0,n-1);
    
    //Print Sorted Array
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
}

