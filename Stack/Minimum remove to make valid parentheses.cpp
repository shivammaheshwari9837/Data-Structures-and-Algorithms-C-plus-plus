/*

Ques:- Given a string s of '(' , ')' and lowercase English characters. 

        Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is valid and return any valid string.

        Formally, a parentheses string is valid if and only if:

        It is the empty string, contains only lowercase characters, or
        It can be written as AB (A concatenated with B), where A and B are valid strings, or
        It can be written as (A), where A is a valid string.
        
Concept:- 1)Here we uses stack , it it similar to problem:- is sequence of brackets is valid or not, with some extra corner cases.

Time - O(n) 
Space - O(n)

*/

    string minRemoveToMakeValid(string s) {
        vector<bool> dis(s.size(),true); //boolean array to see which is valid char or not
         
        stack<int> st1;
        int i = 0;
        
        while(i < s.size())
        {
            if(s[i]>='a' && s[i]<='z')  //if character,discard it
            {
                ++i;
                continue;
            }
            
            if(s[i] == '(') //open bracket,push it into the stack
            {
                st1.push(i);
            }
            else
            {
                if(st1.empty() == true) //if ')' and stack is empty
                {
                    st1.push(i);
                }
                int index = st1.top();
                if(s[index] == '(') //is valid,pop the stack
                {
                    st1.pop();
                }
                else //is invalid,like ---- ' ))',make it invalid
                    dis[i] = false;
            }
            
            ++i;
        }
        
        while(!st1.empty()) //whatever left in stack, like--- ' (((', make it invalid
        {
            dis[st1.top()] = false;
            st1.pop();
        }
        
        string ans;
        for(int j=0;j<dis.size();++j)
        {
            if(dis[j] == true) //whatever now left valid,make a new string as a result
                ans.push_back(s[j]);
        }
        
        return ans;
    }

/*

Concept:- 1)Basically we are checking the balancing of the brackets while iterating the string. 
          2)If we get a sum<0, we know that there is an imbalance and place a @.
          3)Now, it's important to iterate from both sides of the string to check the imbalance.
          
Time - O(n)

*/

string minRemoveToMakeValid(string s) {
        for(int i = 0, sum = 0; i < s.length(); i++) { //from front side
            
            if(s[i] == '(') sum++;
            else if(s[i] == ')' && --sum < 0) { //if sum < 0,make it invalid
                s[i] = '@';
                sum = 0;
            }

        }

        for(int i = s.length() -1, sum = 0; i >= 0; i--) { //from back side
            
            if(s[i] == ')') sum++;
            else if(s[i] == '(' && --sum < 0) {
                s[i] = '@';
                sum = 0;
            }

        }

        s.erase(remove(s.begin(), s.end(), '@'), s.end());
        return s;
    }
