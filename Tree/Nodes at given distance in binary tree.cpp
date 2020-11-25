/*

Ques:- Given a binary tree, a target node in the binary tree, and an integer value k, find all the nodes that are at distance k from the given target node. 
        No parent pointers are available.
        
Concept:- 1)Here, the problem arises, when we try to access the parents and ancestors(including their subtrees) due to binary tree
          2)So, our problem can be solved into two parts:- a)the subtree of target node 
                                                           b)the ancestors(with their subtrees) of target node
          3)All this is done via recursion
          
Time - O(2 * n)  = O(n)
Space - O(height of tree)

*/

vector<int>  ans;
    
    void trav(Node* root,int k) //this function work is only to find the kth value element from current root node
    {
        if(root == NULL)
        return;
        
        if(k == 0) //if element find
        {
            ans.push_back(root->data);
            return;
        }
        
        trav(root->left,k-1); 
        trav(root->right,k-1);
        
    }
    
    int helper(Node* root,int tar,int &k)
    {
        //base..
        if(root == NULL) //if reaches to end of a path
        return -1;
        
        if(root->data == tar) //element found 
        {
            trav(root,k); //now traverse through the target node's subtree
            return 0;
        }
        
        int dl = helper(root->left,tar,k); //this varibles calculate the current level from target node from left subtree
        
        if(dl != -1) //if element was found at left subtree
        {
            if(dl+1 == k) //if valid level 
            ans.push_back(root->data);
            else
            trav(root->right,k-dl-2); //search required distance for element in right subtree
            
            return dl+1; //return level
        }
        
        int dr = helper(root->right,tar,k); //this varibles calculate the current level from target node from right subtree
        
        if(dr != -1) //if element found at right subtree
        {
            if(dr+1 == k) //if required level
            ans.push_back(root->data);
            else
            trav(root->left,k-dr-2); //search required distance for element in left subtree
            
            return dr+1;
        }
        
        return -1;
        
    }

    vector <int> KDistanceNodes(Node* root, int tar , int k)
    {
        // return the sorted vector of all nodes at k dist
        ans.clear();
        helper(root,tar,k);
        sort(ans.begin(),ans.end()); //an question asks in sorted order
        
        return ans;
    }
