#include <iostream>
using namespace std;

int pivot(int arr[], int start, int end){
    int pivot = arr[end];
    int pindex = start;

    for(int i=start;i<end;i++){
        if(arr[i] <= pivot){
            swap(arr[i], arr[pindex]);
            pindex++;
        }
    }

    swap(arr[pindex], arr[end]);
    return pindex;
}

void quickSort(int arr[], int start, int end){
    if(start >= end){
        return;
    }

    int pindex = pivot(arr, start, end);

    quickSort(arr, start, pindex-1);
    quickSort(arr, pindex+1, end);
}

int main() {
    int arr[] = {8,7,6,5,4,3,2};
    int n = 7;
    
    quickSort(arr, 0, n-1);

    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
}

