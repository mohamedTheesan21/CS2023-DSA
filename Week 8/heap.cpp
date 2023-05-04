#include <iostream>
#include <vector>
using namespace std;

// function to heapify the tree
void heapify(int arr[], int n, int root)
{
    int largest = root;
    int right = 2*root + 2;
    int left = 2*root + 1;

    if(left<n && arr[left]>arr[largest]){
        largest = left;
    }
    if(right<n && arr[right]>arr[largest]){
        largest = right;
    }
    if(largest != root){
        swap(arr[root],arr[largest]);
        heapify(arr,n,largest);
    }

}

// implementing heap sort
void heapSort(int arr[], int n)
{
   // build heap
   for(int i=n/2 - 1; i>=0; i--){
        heapify(arr, n, i);
   }
   // extracting elements from heap one by one
   for(int i=n-1;i>=0;i--){
        //move current root to end of the heap tree
        swap(arr[0],arr[i]);
        //call max heap on remaining array
        heapify(arr,i,0);
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
   int n;
   cout<<"Enter the array size"<<endl;
   cin>>n;
   int heap_arr[n];
   cout<<"Enter the array element one by one"<<endl;
   for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        heap_arr[i] = temp;
   }
   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);

   heapSort(heap_arr, n);

   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
}
