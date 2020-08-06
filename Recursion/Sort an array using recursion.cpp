/*

Ques:- Sort an array using recursion

*/

//This insert() is used to insert an 'ele' element at best possible possible
void insert(vector<int> &v1,int ele)
{
	//Base condition....
	if(v1.size() == 0 || v1[v1.size()-1]<=ele)
	{
		v1.push_back(ele);
		return;
	}
	
	//Induction...
	int temp1 = v1[v1.size()-1];
	v1.pop_back();
	
	insert(v1,ele);
	
	v1.push_back(temp1);
	
	return;
}


//This sorting() is just making decisions aka making smaller input..
void sorting(vector<int> &v1)
{
	//Base condtition....
	if(v1.size() == 1)
	return;
	
	//Induction...
	int temp1 = v1[v1.size()-1];
	
	v1.pop_back();
	
	sorting(v1);
	
	insert(v1,temp1);
	
	return;
	
}
