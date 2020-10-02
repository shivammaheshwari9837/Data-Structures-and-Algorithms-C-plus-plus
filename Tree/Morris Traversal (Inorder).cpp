/*

Ques:- Given the root of a binary tree, return the inorder traversal of its nodes' values.
Concept:- Morris Traversal Algorihtm

Time- O(2*n) ie. O(n)
Space - O(1)

Note:- Here tree structure will be changed

*/


vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;

        TreeNode *curr = root,*rightMostInLeftSubtree = NULL;
        
        while(curr)
        {
            if(curr->left) //if it has left child
            {
                /*
                link current node as right child of the 
                rightmost node in left subtree (inorder predecessor)
                if not done already
                */
                //find rightmost node in left subtree
                rightMostInLeftSubtree = curr->left;
                
                while(rightMostInLeftSubtree->right && rightMostInLeftSubtree->right != curr)
                {
                    rightMostInLeftSubtree = rightMostInLeftSubtree->right;
                }
                
                //if current node is not linked as right child to 
                //its inorder predecessor then link it
                if(!rightMostInLeftSubtree->right)
                {
                    rightMostInLeftSubtree->right = curr;
                    curr = curr->left;
                }
                else
                {
                    /*
                    if alreday found linked in,
                    then it means it has already been 
                    linked in any previous traversal 
                    and we have finished traversing the left subtree
                    so traverse the current node and remove 
                    the link to restore tree
                    */
                    ans.push_back(curr->val);
                    rightMostInLeftSubtree->right = NULL;
                    
                    //move to right now since left subtree 
                    //has been traversed already
                    curr = curr->right;
                }
            }
            else
            {
                //traverse the node and move to right child
                ans.push_back(curr->val);
                curr = curr->right;
            }
        }
        
        return ans;
        
    }
