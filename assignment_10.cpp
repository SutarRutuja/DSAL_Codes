/*
  Implement the Heap sort algorithm demonstrating heap data structure
with modularity of programming language*/

#include <iostream>
#include <vector>


using namespace std;


// Function to heapify a subtree rooted at index `i`
void heapify(vector<int>& arr, int n, int i) {
   int largest = i;          // Initialize largest as root
   int left = 2 * i + 1;      // Left child
   int right = 2 * i + 2;     // Right child


   // If left child is larger than root
   if (left < n && arr[left] > arr[largest])
       largest = left;


   // If right child is larger than the largest so far
   if (right < n && arr[right] > arr[largest])
       largest = right;


   // If the largest is not the root
   if (largest != i) {
       swap(arr[i], arr[largest]); // Swap root with largest
       heapify(arr, n, largest);   // Recursively heapify the affected subtree
   }
}


// Function to build a max heap
void buildMaxHeap(vector<int>& arr, int n) {
   // Start from the last non-leaf node and heapify each node
   for (int i = n / 2 - 1; i >= 0; i--)
       heapify(arr, n, i);
}




// Heap Sort function
void heapSort(vector<int>& arr) {
   int n = arr.size();
   buildMaxHeap(arr, n);  // Step 1: Build max heap


   // Step 2: Extract elements from the heap one by one
   for (int i = n - 1; i > 0; i--) {
       swap(arr[0], arr[i]);  // Move the largest element to the end
       heapify(arr, i, 0);    // Heapify the reduced heap
   }
}


// Function to print the array
void printArray(const vector<int>& arr) {
   for (int num : arr)
       cout << num << " ";
   cout << endl;
}


// Main function to test Heap Sort
int main() {
   cout<<"\nMenu\n1.Enter array element\n2.Heap sort\n3.Exit"<<endl;


   vector<int> arr;
for(int i=0;i<20;i++){
   cout<<"Enter your choice: ";
   int k;


   cin>>k;
   if(k==1){
       arr.clear();
      
        cout<<"No of element in array are: ";
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
           cout<<"Enter element: ";
           int m;
           cin>>m;
           arr.push_back(m);


        }


       cout << "Original Array: ";
       printArray(arr);
  
   }
   if(k==2){
       cout << "Original Array: ";
       printArray(arr);
       heapSort(arr);
  
       cout << "Sorted Array: ";
       printArray(arr);
   }
   if(k==3){
    break;
   }
}
 


   return 0;
}



