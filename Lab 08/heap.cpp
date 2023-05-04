#include <iostream>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   // build heapify
    int largest = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != root) {
        swap(arr[root], arr[largest]);
        heapify(arr, n, largest);
    }
}
  
// implementing heap sort
void heapSort(int arr[], int n)
{
   // build heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // extracting elements from heap one by one
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
  
/* print contents of array */
void displayArray(int arr[], int n){
   for (int i=0; i<n; ++i)
       cout << arr[i] << " ";
       cout << "\n";
}


// main program
int main()
{

   int size; // size of array
   cout<<"Enter size of the Array :";
   cin>>size;

   int arr[size];
   cout<<"Input array"<<endl;
   // taking inputs to array
   for(int i = 0;i < size;i++){
       cin>>arr[i];
   }

   heapSort(arr, size);

   cout << "Sorted array"<<endl;
   displayArray(arr, size);
}