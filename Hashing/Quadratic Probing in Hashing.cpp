/*

Ques :- Given an array of integers and a Hash table. Fill the elements of the array into the hash table by using Quadratic Probing in case of collisions.

Concept:- Quadratic probing is a collision handling technique in hashing. Quadratic probing says that whenever a collision occurs, search for i^2 position.

Time - O(n * hashTableSize)

*/

void QuadraticProbing(vector <int> &hash, int hashSize, int arr[], int n)
{
    //Your code here
    for(int i=0;i<hashSize;++i)
    hash[i] = -1;
    
    int isLeft = hashSize;
    
    for(int i=0;i<n;++i)
    {
        int index = arr[i]%hashSize;
        
        for(int j=1;hash[index]!=-1 && isLeft>0 ; ++j) //iterating towards the next index
        {
            index = (arr[i] + (j*j))%hashSize;
        }
        
        if(isLeft > 0)
        {
            --isLeft;
            hash[index] = arr[i];
        }
        
    }
    
}
