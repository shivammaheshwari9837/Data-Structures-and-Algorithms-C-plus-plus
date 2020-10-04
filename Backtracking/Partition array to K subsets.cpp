/*

Ques:- Given an array of integers nums and a positive integer k, find whether it's possible to divide this array into k non-empty subsets whose sums are all equal.

Concept:-1)Here we will use the concept of DFS + Backtracking 
         2)We have two choices for every ith subset from K subsest ie. a)if an element is not taken
                                                                                  i)Take it
                                                                                  ii)Not take it
                                                                       b)if element is not taken,than do nothing

*/

bool dfs(int index,int &siz,vector<int> &A,int K,int &tarSum,int currSum,vector<bool> &isVisit)
    {
        //base...
        if(K == 1) //than, all set are done
            return true;
        
        if(tarSum == currSum) return dfs(0,siz,A,K-1,tarSum,0,isVisit); //one subset is found,thus reduce the value of K
        
        if(currSum > tarSum) //means extra element is added
            return false;
        
        for(int i=index;i<siz;++i)
        {
            if(isVisit[i] != true)
            {
                isVisit[i] = true; //take it
                if(dfs(i+1,siz,A,K,tarSum,currSum + A[i],isVisit)) return true; //if taking making a valid set,than return true
                isVisit[i] = false; //if not possible to make a set,than make element false,that is backtracking 
            }
        }
        
        return false;
    }
    
    bool canPartitionKSubsets(vector<int>& A, int K) {
        
        int sum = 0;
        int N = A.size();
        
        for(int i=0;i<N;++i) sum += A[i];
        
        if(sum % K != 0) //if total sum can be divided into K parts or not
            return false;
        
        vector<bool> isVisit(N,false); //maintain a boolean array,so to avoid redundancy
        
        int tarSum = sum/K;
        int currSum = 0;
        
        bool ans = dfs(0,N,A,K,tarSum,currSum,isVisit);  //(currentIndex,size,array,K,target sum,currSum,visited array)
            
        return ans;
    }
