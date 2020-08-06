/*

Ques :- Permutation with spaces...

*/


void letterCase(int index,string temp1)
{
	//Base condtion....
	if(index >= (temp1.size()-1))
	{
//		cout<<temp1<<"|";
		ans.push_back(temp1);
		return;
	}
	
	//Induction/Hypothesis...
	
	letterCase(index+1,temp1);
	
	string t1 = temp1.substr(0,index+1);
	t1+=' ';
	t1+=(temp1.substr(index+1,temp1.size() - (index+1 )));
	
	letterCase(index+2,t1);
	
	return;
}
