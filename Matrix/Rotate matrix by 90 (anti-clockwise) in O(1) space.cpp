/*

Ques :-Rotate matrix by 90 (anti-clockwise) in O(1) space

Theory:- To solve the question without any extra space, rotate the array in form of squares,
         dividing the matrix into squares or cycles. For example,
        A 4 X 4 matrix will have 2 cycles. The first cycle is formed by its 1st row, last column, 
        last row and 1st column. The second cycle is formed by 2nd row, second-last column, 
        second-last row and 2nd column. The idea is for each square cycle, swap the elements
         involved with the corresponding cell in the matrix in anti-clockwise direction i.e. from 
        top to left, left to bottom, bottom to right and from right to top one at a time using 
        nothing but a temporary variable to achieve this.

*/


for(int x=0;x<n/2;++x)
    {
        for(int y=x;y<n-x-1;++y)
        {
            int temp=mat[x][y];
            
            mat[x][y]=mat[y][n-x-1];
            
            mat[y][n-x-1]=mat[n-x-1][n-y-1];
            
            mat[n-x-1][n-y-1]=mat[n-y-1][x];
            
            mat[n-y-1][x]=temp;
        }
    }
    
    
    /*
    
    Note:- Reverse is for right rotation of a matrix...(similar)
    
    */
