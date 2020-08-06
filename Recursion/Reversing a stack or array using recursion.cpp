/*

Ques :-  Reversing a stack/array using recursion:

*/

void insert(vector<int> &A,int ele)
{
    //Base condition...
    if(A.size() == 0)
    {
        A.push_back(ele);
        return;
    }
    
    //Hypo..
    int temp1 = A[A.size()-1];
    
    A.pop_back();
    
    insert(A,ele);
    
    A.push_back(temp1);
    
    return;
}
