/*

Ques:- Implement Quick Sort

Concept:- 1.)We pick an element ie. Pivot, and find an appropriate place for it

Time-----
      1.)Best,Average:- O(nlogn)
      2.)Worst - O(n^2)

*/


int partition (int arr[], int low, int high)
{
   // Your code here
   int pivot = arr[low];
   int i = low + 1;
   
   for(int j=low + 1;j <= high; ++j)
   {
       if(arr[j] < pivot)
       {
           swap(arr[j],arr[i]);
           i += 1;
       }
   }
   
   swap(arr[low],arr[i-1]);
   
   return i-1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high)     {
        // pi is partitioning index, arr[p] is now  at right place
        int pi = partition(arr, low, high);
        // Separately sort elements before / partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

