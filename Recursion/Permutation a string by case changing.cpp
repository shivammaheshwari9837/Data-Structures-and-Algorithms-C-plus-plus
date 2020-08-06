/*

Ques :- Permutation a string by case changing...

*/

void caseChange(int index,string temp1)
{
	//Base condition....
	if(index>=n)
	{
		cout<<temp1<<" ";
		return;
	}
	
	//Hypothesis....
	
	caseChange(index+1,temp1);
	
	if(islower( str[index]))
	{
		temp1[index] = temp1[index] - 32;
	}
	else
	{
		temp1[index] = temp1[index] + 32;
	}
	
	caseChange(index+1,temp1);
	
	return;
}
