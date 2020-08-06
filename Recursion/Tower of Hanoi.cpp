/*

Ques :- Tower of Hanoi

*/

void toh(int n,int sou,int des,int help)
{
	//Base condtion....
	
	if(n == 1)
	{
		cout<<"move disk "<<n<<" from rod "<<sou<<" to rod "<<des<<"\n";
		return;
	}
	
	//Hypothesis....
	toh(n-1,sou,help,des);
	cout<<"move disk "<<n<<" from rod "<<sou<<" to rod "<<des<<"\n";
	toh(n-1,help,des,sou);
	
}
