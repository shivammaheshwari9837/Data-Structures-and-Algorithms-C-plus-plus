/*

Ques:- Given a string S, find the longest palindromic substring in the string S.

*/

#include<bits/stdc++.h>
using namespace std;

string convert(string str)
{
    string temp;
    temp.push_back('$');

    for(int i=0;i<str.size();++i)
    {
        temp.push_back('#');
        temp.push_back(str[i]);
    }

    temp+="#@";
    return temp;
}

int main()
{
    string str;
    cin>>str;

    string newStr = convert(str);

    int P[newStr.size()+1] = {0};

    int center = 0,right = 0;

    for(int i=1;i<newStr.size()-1;++i)
    {
        int mirror = 2*center-i;

        if(i<right)
        P[i] = min(P[mirror],right-i);

        while(newStr[i+1+P[i]] == newStr[i-1-P[i]])
        ++P[i];

        if(i+P[i] > right)
        {
            center = i;
            right = P[i]+i;
        }
    }

    int ans = 0;
    int index;
    for(int i=0;i<newStr.size();++i)
    {
        if(P[i] > ans)
        {
            ans = P[i];
            index = i;
        }
    }

    cout<<ans<<"\n";
    cout<<str.substr((index-1-ans)/2,ans);
}
