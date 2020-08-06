/*

Ques :-Given two binary trees with head reference as T and S having at most N nodes. The task is to check if S is present as subtree in T.

Method 1:- O(s_nodes * t_nodes) or O(n^2) , space - O(min_nodes(s,t)
Concept:- 1.)Traversing each node of T subtree and checking S is a subtree of T or not

*/

     bool isSame(TreeNode* s,TreeNode *t)
    {
        if(s == NULL || t == NULL) 
        {
            return (s == NULL && t == NULL);  // both must be null or not null
        }
        else if(s->val == t->val) // if elemnt matches, continue search
            return isSame(s->left,t->left) && isSame(s->right,t->right); 
        else
            return false;
    }

    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(s == NULL)  //if s is null
            return false;
        else if(isSame(s,t)) // checking s (as a root) and t (as a root)
            return true;
        else
            return isSubtree(s->left,t) || isSubtree(s->right,t); //else  moving towards different level it. left and right 
        
    }
    
    
    /*
    
    Method 2:- O(n) time
    Concept:- Rabin Karp(at end)
    
    */
