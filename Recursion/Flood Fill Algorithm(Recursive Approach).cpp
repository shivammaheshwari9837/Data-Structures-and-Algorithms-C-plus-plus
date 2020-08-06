/*

Ques :- Flood Fill Algorithm(Recursive Approach)

*/

void floodFill(int i,int j)
{
	//Base condtion......
	if(i<0 || i>=m || j<0 || j>=n || mat[i][j]!=se )
	return;
	
	
	//Induction...
	
	mat[i][j] = color;
	
	//left.....
	if(mat[i][j-1] == se)
	{
		floodFill(i,j-1);
	}
	
	//right...
	if(mat[i][j+1] == se)
	{
		floodFill(i,j+1);
	}
	
	//up....
	if(mat[i-1][j] == se)
	{
		floodFill(i-1,j);
	}
	
	//down...
	if(mat[i+1][j] == se)
	{
		floodFill(i+1,j);
	}
	
	return;
}
