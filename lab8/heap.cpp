#include <iostream>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   // build heapify
   int maxValue = root;
   int leftValue = 2*root + 1;
   int rightValue = 2*root + 2;

   // check for maximum from left and root values
   if(leftValue < n && arr[leftValue] > arr[maxValue]){
      maxValue = leftValue;
   }

   // check for maximum from right and root values
   if(rightValue < n && arr[rightValue] > arr[maxValue]){
      maxValue = rightValue;
   }

   // check if root needs to change
   if(maxValue != root){
    swap(arr[root], arr[maxValue]); // swaps to root with the largest value
    heapify(arr, n, maxValue); // heapify the changed sub tree
   }
  
   
}
  
// implementing heap sort
void heapSort(int arr[], int n)
{
   // build heap
   for(int i = n/2 - 1; i >= 0; i--){
    heapify(arr, n, i);
   }
  
   // extracting elements from heap one by one
   for(int i = n-1; i >= 0; i--){
    swap(arr[0],arr[i]);
    heapify(arr, i, 0);
   }
   
}
  
/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  
// main program
int main()
{
   cout << "Enter the size of input array: ";
   int sizeOfArray;
   cin >> sizeOfArray;

   int heap_arr[sizeOfArray];
   
   for(int i=0; i<sizeOfArray; i++)
      heap_arr[i]=rand()%100;  //Generate random inputs for the array
   
   int n = sizeof(heap_arr)/sizeof(heap_arr[0]);
      
   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);
  
   heapSort(heap_arr, n);
  
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
}