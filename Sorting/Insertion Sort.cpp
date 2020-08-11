/*

Ques:- Implement Insertion Sort

Time - O(n^2)
Best = O(n), if array is already sorted

*/


void swap(int &a,int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void insert(int arr[], int i)
{
    // Your code here  
    for(int j=i;j>=1;--j)
    {
        if(arr[j] < arr[j-1])
        {
            swap(arr[j],arr[j-1]);
        }
        else
        break;
    }
}

void insertionSort(int arr[], int n) //start...........
{
   int i;
   for (i = 1; i < n; i++)
      insert(arr, i);
}
