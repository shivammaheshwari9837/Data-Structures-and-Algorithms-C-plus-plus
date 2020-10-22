/*

Ques:- Implement Selectio Sort

Concept:- 1.) We pick a position i, and select the most appropriate element for it

*/

int select(int arr[], int i)
{
    // Your code here
    
    for(int j=i-1;j>=0;--j)
    {
        if(arr[j] > arr[i])
        {
            i = j;
        }
    }
    return i;
}


void selectionSort(int arr[], int n)
{
   int i, j;
   for (i = n-1; i >=0; i--)      
   {
        int j = select(arr, i);
        swap(&arr[i], &arr[j]);
   }
}
