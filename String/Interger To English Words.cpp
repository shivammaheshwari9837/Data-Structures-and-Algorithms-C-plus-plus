// Ques:- Convert a non-negative integer num to its English words representation.

//Time:- Time - O(lenght of number), Space - O(1) or stack space 

// Code:- 


class Solution {
public:
    string digits[20] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    string tens[10] = {"Zero", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    
    string intToString(int num){
        if(num >= 1000000000)
            return intToString(num/1000000000) + " Billion" + intToString(num%1000000000);
        else if(num >= 1000000)
            return intToString(num/1000000) + " Million" + intToString(num%1000000);
        else if(num >= 1000)
            return intToString(num/1000) + " Thousand" + intToString(num%1000);
        else if(num >= 100)
            return intToString(num/100) + " Hundred" + intToString(num%100);
        else if(num >= 20)
            return " " + tens[num/10] + intToString(num%10);
        else if(num >= 1)
            return " " + digits[num];
        else
            return "";
    }
    
    string numberToWords(int num) {
        if(num == 0)
            return "Zero";
        else{
            string ans = intToString(num);
            cout<<ans;
            return ans.substr(1,ans.size()-1);
        }
    }
};

