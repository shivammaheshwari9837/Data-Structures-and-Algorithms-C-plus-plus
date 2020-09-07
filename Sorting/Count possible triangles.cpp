/*

Ques:- Given an unsorted array of positive integers. Find the number of triangles that can be formed with three different array elements as lengths of three sides of triangles. 

Concept:- 1)Sort the element of the array .Sorting would help you to maintain the condition that  for any three sides of  the triangle  a,b and c,ie. some a+b > c 
          2)Than we first fix i pointer from i=n-1 to i>1, than we use two pointer algorithm
          3)We make two pointers,named as low and high
          4)Thus aur sides become at pointer i, and high, varying low from low to high-1

Time - O(n^2)
Space - O(1)

*/

int findNumberOfTriangles(int arr[], int n)
    {
        sort(arr,arr+n);
        // code here
        int coun = 0;
        
        for(int i=n-1;i>1;--i) //making pointer i
        {
            int low = 0,high = i-1; //setting up low and high too
            while(low<high)
            {
                if(arr[low]+arr[high] > arr[i]) //than if some valid,than count all members from low to high-1, fixing high and i pointer as sides
                {
                    coun += (high-low);
                    --high; //fixing some lower high
                }
                else
                ++low;
            }
        }
        return coun;
    }
