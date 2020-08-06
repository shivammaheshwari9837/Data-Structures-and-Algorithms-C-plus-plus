/*

Ques :- Kth symbol in a grammar

Method 1:-Using recusion...
Concept:- Eg:-  0
		0 1
		0 1 1 0
		0 1 1 0 1 0 0 1   ------->The first half is same as upper, next half is complement
						of upper...
            
            
  */
  
  
  int kthGrammar(int N, int K) {
        
        //Base condition...
        if(N == 1 && K == 1)
            return 0;
        
        int mid = pow(2,N-1)/2;
        
        if(K<=mid)
            return kthGrammar(N-1,K);
        else
            return(! kthGrammar(N-1,K-mid));
        
    }
    
    
    
    /*
    
    Method 2:- USing Bits...
Concept:- Observe only...
    
    */
    
    
    int kthGrammar(int N, int K) {
        
        int setBit = __builtin_popcount(K-1);
        
        if(setBit%2 == 0)
            return 0;
        else
            return 1;
        
    }
