/*

Ques:- Given two Binary Trees. Check whether they are Isomorphic or not.
       Isomorphic:-Two trees are called isomorphic if one of them can be obtained from other by a series of flips, i.e. by swapping left and right children of a number of nodes.
       
Comcept:- 1)Here we will simply recurr in all possible ways to match the trees

Time - O(min(h1,h2) ),where h1 and h2 are heights of given tree
Space - O(min(h1,h2 )

*/

bool check(Node *root1,Node *root2)
{
    //base....
    if(root1 == NULL && root2 == NULL) //if both ends
    return true;
    
    if(root1 == NULL || root2 == NULL) //if anyone of tree ends,than false
    return false;
    
    if(root1->data == root2->data) //first root's data must match,than we have to proceed
    {
        bool a = check(root1->left,root2->left);  
        bool b = check(root1->right,root2->right);
        
        bool c = check(root1->right,root2->left); //these two are the opposite directions
        bool d = check(root1->left,root2->right);
        
        bool b1 = a&b,b2 = c&d;
        
        return b1|b2;
    }
    else
    return false;
}

bool isIsomorphic(Node *root1,Node *root2)
{
//add code here.
    bool ans = check(root1,root2);
    return ans;
}
