/*

Ques:- Implement Bubble Sort

Time - O(n^2)
Space - O(n)

Concept:- 1.)At every pass , we will get the largest element at bottom


*/

void bubble(int arr[], int i, int n)
{
    // Your code here 
    for(int j=0;j<n-i-1;++j)
    {
        if(arr[j] > arr[j+1])
        {
            int temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
        }
    }
}

void bubbleSort(int arr[], int n)
{
   for (int i = 0; i < n-1; i++)      
        bubble(arr, i, n);
}
