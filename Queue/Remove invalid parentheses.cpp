/*

Ques:- Remove the minimum number of invalid parentheses in order to make the input string valid. Return all possible results.

Note: The input string may contain letters other than the parentheses ( and ).

Concept:- 1)Here we we do removal of brackets one by one, means first check all possiblity with 1 parantheses removed, than 2,3....and so on
          2)if at any instant we find any valid sequence , than just we will check upto that length sequenecs
          
 Time - O(n^3)
 Space - O(n^3)

*/

bool isValid(string s)
    {
        int coun = 0;
        for(int i=0;i<s.size();++i)
        {
            if(s[i] == '(')
                ++coun;
            else if(s[i] == ')')
                --coun;
            
            if(coun < 0)
                return false;
        }
        
        return (coun == 0);
    }
    
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        
        unordered_map<string,bool> visit; //visited map, to avoid re-checking of a particular sequence
        queue<string> q1;
        q1.push(s);
        bool found = false; //if some particular sequence of length is valid,than only check upto that lenght(since we have to find minimum removals)
        
        while(!q1.empty())
        {
            string temp = q1.front();
            q1.pop();
            
            if(visit[temp] == true) continue; //if already current sequqnce is checked
            visit[temp] = true;
            
            if(isValid(temp)) //if valid sequence
            {
                found = true;
                ans.push_back(temp); //push in the result
            }
            
            if(found) continue; //if found, do not continue
            
            for(int i=0;i<temp.size();++i)
            {
                if(temp[i] == '(' || temp[i] == ')')
                {
                    string t1 = temp.substr(0,i) + temp.substr(i+1,temp.size() - (i+1)); //here left temp = "(())", than we pushes = [()),((),(()())] 
                    q1.push(t1);
                }
                
            }
        }
        
        if(ans.size() == 0) //if none sequence is valid, than make answer of only left alphabets
        {
            string t3;
            for(int i=0;i<s.size();++i)
            {
                if(s[i]>='a' && s[i]<='z')
                    t3.push_back(s[i]);
            }
            ans.push_back(t3);
        }
        
        return ans;
    }
