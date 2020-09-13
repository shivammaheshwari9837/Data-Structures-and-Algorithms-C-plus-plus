/*

Ques:- Given two strings 'str' and a wildcard pattern 'pattern' of length N and M respectively,  You have to print '1' if the wildcard pattern is matched with str else print '0' .

The wildcard pattern can include the characters ‘?’ and ‘*’
‘?’ – matches any single character
‘*’ – Matches any sequence of characters (including the empty sequence)

Note: The matching should cover the entire str (not partial str).

Concept:- 1)Here we have choices ---> 1)if there is no wildcard character, and both character in pattern and str string matches, move forward
                                      2)if pattern has '?' as character than, quit one character form string
                                      3)if pattern has '*' as a character , than we have choices ----- a)either include the string character in subsequence of '*'
                                                                                                       b)ignore the '*',ie make it as empty subsequence
                                                                                                       
                                                                                                       
          2)in base condtion of recurion, important to note :-----if string ends,and pattern has only left '*' , than true also
          
Time - O(n*m) 
Space - O(n*m)

*/

int dp[205][205];


bool wild(int pattInd,string &patt,int strInd,string &str)
{
	//base...
	if(strInd<0 && pattInd<0) //if both ends, than true
	return true;
	else if(pattInd<0) // if pattern ends,than false
	return false;
	else if(strInd<0) //if string str ends, check the pattern
	{
	    while(pattInd >= 0) //if string ends,and pattern has only left '*' , than true also
	    {
	        if(patt[pattInd] != '*')
	        return false;
	        --pattInd;
	    }
	    return true;
	}
	
	if(dp[pattInd][strInd] != -1)
	return dp[pattInd][strInd];
	
	
	if(patt[pattInd] == str[strInd]) //if there is no wildcard character, and both character in pattern and str string matches, move forward
	{
		return dp[pattInd][strInd] = wild(pattInd-1,patt,strInd-1,str);
	}
	else if(patt[pattInd] == '?')
	{
		return dp[pattInd][strInd] = wild(pattInd-1,patt,strInd-1,str);  //if pattern has '?' as character than, quit one character form string
	}
	else if(patt[pattInd] == '*') //if pattern has '*' as a character
	{
		//maintain * ...
		bool a = wild(pattInd,patt,strInd-1,str); //either include the string character in subsequence of '*'
		
		//making * empty
		bool b = wild(pattInd-1,patt,strInd,str); //ignore the '*',ie make it as empty subsequence
		
		return (dp[pattInd][strInd] = (a| b) );
	}
	else
	return dp[pattInd][strInd] = false;
}

/*You are required to complete this method*/
int wildCard(string patt,string str)
{
    for(int i=0;i<=patt.size();++i)
	for(int j=0;j<=str.size();++j)
	dp[i][j] = -1;
	
	int ans = wild(patt.size()-1,patt,str.size()-1,str);
	return ans;
}
