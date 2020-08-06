/*

Ques :- Longest Palindrome Substring (T = O(n^2) )


Concept:- 1.Fix an i index of string, than considered it as a middle element of a palindrome
	2. Two cases a) odd length palindrome
			b) even lenght palindrome
	3. than expand it in the both directions too
  
  */
  
  
  int expand(string &s,int left,int right)
    {
        while(left>=0 && right<s.length() && s[left] == s[right])
        {
            --left;
            ++right;
        }
        
        return (right-left-1);
    }
    
    string longestPalindrome(string s) {
        if(s.length() == 0)
            return "";
        
        int start=0,end=0;
        
        for(int i=0;i<s.length();++i)
        {
            int len1 = expand(s,i,i+1);
            int len2 = expand(s,i,i);
            int len = max(len1,len2);
            
            if(len > (end-start +1))
            {
                start = i - (len-1)/2;
                end = i + len/2;
            }
        }
  
  
