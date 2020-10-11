Sign In
Sign In
Home
Courses
Hire With Us
Algorithmskeyboard_arrow_down
Data Structureskeyboard_arrow_down
Languageskeyboard_arrow_down
Interview Cornerkeyboard_arrow_down
GATEkeyboard_arrow_down
CS Subjectskeyboard_arrow_down
Studentkeyboard_arrow_down
GBlog
Puzzles
What's New ?
▲
Time Complexities of all Sorting Algorithms
Selection Sort
Bubble Sort
Insertion Sort
Merge Sort
QuickSort
HeapSort
Binary Heap
Time Complexity of building a heap
Applications of Heap Data Structure
Binomial Heap
Fibonacci Heap | Set 1 (Introduction)
Fibonacci Heap – Insertion and Union
Fibonacci Heap – Deletion, Extract min and Decrease key
Leftist Tree / Leftist Heap
K-ary Heap
Iterative HeapSort
Program to check if a given number is Lucky (all digits are different)
Lucky Numbers
Write a program to add two numbers in base 14
Babylonian method for square root
Square root of an integer
Find square root of number upto given precision using binary search
Binary Search
Linear Search
Selection Sort
Last Updated: 02-05-2019
The selection sort algorithm sorts an array by repeatedly finding the minimum element (considering ascending order) from unsorted part and putting it at the beginning. The algorithm maintains two subarrays in a given array.

1) The subarray which is already sorted.
2) Remaining subarray which is unsorted.

In every iteration of selection sort, the minimum element (considering ascending order) from the unsorted subarray is picked and moved to the sorted subarray.

Following example explains the above steps:



arr[] = 64 25 12 22 11

// Find the minimum element in arr[0...4]
// and place it at beginning
11 25 12 22 64

// Find the minimum element in arr[1...4]
// and place it at beginning of arr[1...4]
11 12 25 22 64

// Find the minimum element in arr[2...4]
// and place it at beginning of arr[2...4]
11 12 22 25 64

// Find the minimum element in arr[3...4]
// and place it at beginning of arr[3...4]
11 12 22 25 64 
Flowchart of the Selection Sort:




Recommended: Please solve it on “PRACTICE” first, before moving on to the solution.
filter_none
edit
play_arrow

brightness_5
// C++ program for implementation of selection sort  
#include <bits/stdc++.h> 
using namespace std; 
  
void swap(int *xp, int *yp)  
{  
    int temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
}  
  
void selectionSort(int arr[], int n)  
{  
    int i, j, min_idx;  
  
    // One by one move boundary of unsorted subarray  
    for (i = 0; i < n-1; i++)  
    {  
        // Find the minimum element in unsorted array  
        min_idx = i;  
        for (j = i+1; j < n; j++)  
        if (arr[j] < arr[min_idx])  
            min_idx = j;  
  
        // Swap the found minimum element with the first element  
        swap(&arr[min_idx], &arr[i]);  
    }  
}  
  
/* Function to print an array */
void printArray(int arr[], int size)  
{  
    int i;  
    for (i=0; i < size; i++)  
        cout << arr[i] << " ";  
    cout << endl;  
}  
  
// Driver program to test above functions  
int main()  
{  
    int arr[] = {64, 25, 12, 22, 11};  
    int n = sizeof(arr)/sizeof(arr[0]);  
    selectionSort(arr, n);  
    cout << "Sorted array: \n";  
    printArray(arr, n);  
    return 0;  
}  
