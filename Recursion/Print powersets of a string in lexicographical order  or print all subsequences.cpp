/*

Ques:- Print powersets of a string in lexicographical order...or print all subsequences

*/

void powerSets(string temp1,int index)
{
	//base condition.......
	if(index == n)
	{
		if(temp1.size()!=0)
		ans.push_back(temp1);
		return;
	}
	
	//Hypothesis/Induction....
	powerSets(temp1,index+1);
	
	temp1.push_back(str[index]);
	
	powerSets(temp1,index+1);
	
	return;
	
}
