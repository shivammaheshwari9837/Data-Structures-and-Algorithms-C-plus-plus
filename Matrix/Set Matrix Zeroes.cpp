/*

Ques:- Given an m x n matrix. If an element is 0, set its entire row and column to 0. Do it in-place.

Concept:- 1)Rather than using additional variables to keep track of rows and columns to be reset, we use the matrix itself as the indicators.
          2)The idea is that we can use the first cell of every row and column as a flag. This flag would determine whether a row or column has been set to zero. 
          This means for every cell instead of going to M+NM+N cells and setting it to zero we just set the flag in two cells.
          3)The condition:-    if cell[i][j] == 0 {
                      cell[i][0] = 0
                      cell[0][j] = 0
                  }
                  
          4)These flags are used later to update the matrix. If the first cell of a row is set to zero this means the row should be marked zero. If the first cell of a 
          column is set to zero this means the column should be marked zero.
          
Time - O(n * m) 
Space - O(1)

*/

    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        bool firRow = false,firCol = false; //used for getting information only about first row and first column,as these will be updated in further process redundantly
        
        for(int i=0;i<m;++i) //for first row
        {
            if(matrix[0][i] == 0)
                firRow = true;
        }
        
        for(int i=0;i<n;++i) //for first column
        {
            if(matrix[i][0] == 0)
                firCol = true;
        }
        
        for(int i=1;i<n;++i)
            for(int j=1;j<m;++j)
            {
                if(matrix[i][j] == 0) //storing information at fisrt row and first column
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        
        for(int i=1;i<n;++i)
        {
            if(matrix[i][0] == 0) //inplace changing of the matrix as a row
            {
                for(int j=1;j<m;++j)
                    matrix[i][j] = 0;
            }
        }
        
        for(int i=1;i<m;++i)
        {
            if(matrix[0][i] == 0) //inplace changing of the matrix as a column
            {
                for(int j=1;j<n;++j)
                    matrix[j][i] = 0;
            }
        }
        
        if(firRow) for(int i=0;i<m;++i) matrix[0][i] = 0; //for first row
        if(firCol) for(int i=0;i<n;++i) matrix[i][0] = 0; //for first column
        
    }
