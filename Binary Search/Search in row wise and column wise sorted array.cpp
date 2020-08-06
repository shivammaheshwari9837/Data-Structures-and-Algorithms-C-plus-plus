/*

Ques :- Search in row wise and column wise sorted array(Time - O(n+m) )

*/

void work()
{
	int n,m;
	
	cin>>n>>m;
	
	int mat[n][m];
	
	for(int i=0;i<n;++i)
	for(int j=0;j<m;++j)
	cin>>mat[i][j];
	
	int key;
	cin>>key;
	
	int row=0,col=m-1;
	bool ans=0;
	
	while(row>=0 && row<n && col>=0 && col<m)
	{
		if(mat[row][col] == key)
		{
			ans=1;
			break;
		}
		else if(key > mat[row][col])
		++row;
		else
		--col;
	}
	
	cout<<ans;
}
