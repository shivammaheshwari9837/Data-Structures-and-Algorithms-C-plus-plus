/*

Ques :- Given strings s1 and s2, you need to find if s2 is a rotated version of the string s1. The strings are lowercase.

Concept:-Step 1: Create a temp string and store concatenation of str1 to str1 in temp. 
             temp = str1.str1
	Step 2: If str2 is a substring of temp then str1 and str2 are 
            rotations of each other using KMP/Rabin Carp/Z algorithm.. or inbuilt function find can be 	used.

*/


void work()
{
	string s1,s2;
	cin>>s1>>s2;
	
	if(s1.length() != s2.length())
	{
	    cout<<0;
	    return;
	}
	
	s1+=s1;
	
	if(s1.find(s2) != string::npos)
	cout<<1;
	else
	cout<<0;
}

