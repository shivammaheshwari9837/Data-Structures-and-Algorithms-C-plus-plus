/*

Ques :- Spirally Traversal of a matrix..

*/


void work()
{
	int n,m;
	cin>>n>>m;
	
	int mat[n][m];
	
	for(int i=0;i<n;++i) for(int j=0;j<m;++j) cin>>mat[i][j];
	
	int left = 0,right = m-1,down = n-1,up=0;
	
	while(left<=right && up<=down)
	{
		for(int i=left;i<=right;++i)
		cout<<mat[up][i]<<" ";
		
		++up;
		
		for(int i=up;i<=down;++i)
		cout<<mat[i][right]<<" ";
		
		--right;
		
		if(up<=down)
		{
			for(int i=right;i>=left;--i)
			cout<<mat[down][i]<<" ";
		}
		
		
		--down;
		
		if(left<=right)
		{
		    for(int i=down;i>=up;--i)
		    cout<<mat[i][left]<<" ";
		}
		
		
		++left;
	}
}
