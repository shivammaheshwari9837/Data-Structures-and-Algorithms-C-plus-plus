/*

Ques :- Given an array of integers and a hash table size. Fill the array elements into a hash table using Linear Probing to handle collisions.

Concept:- Linear probing is a collision handling technique in hashing. Linear probing says that whenever a collision occurs, search for the immediate next position.

Time - O(n * hashTableSize)
Space - O(1)

*/

// insert all the elements of the array arr[] (having size N)
// into the hash table hash[] (having size hashSize)
vector<int> linearProbing(int hashSize, int arr[], int n)
{
    //Your code here
    vector<int> hash(hashSize,-1); //creating an empty hashTable
    int empty = hashSize;
    
    for(int i=0;i<n;++i)
    {
        int index = arr[i]%hashSize; //do mapping 
        
        while(empty>0 && hash[index] != -1)
        {
            index = (index+1)%hashSize;
        }
        
        if(empty > 0)
        {
            hash[index] = arr[i];
            --empty;
        }
    }
    
    return hash;
    
}
