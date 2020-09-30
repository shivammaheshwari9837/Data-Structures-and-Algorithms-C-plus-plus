/*

Ques:- Given a binary tree denoted by root node A and a leaf node B from this tree.

        It is known that all nodes connected to a given node (left child, right child and parent) get burned in 1 second. Then all the nodes which are connected through one intermediate 
        get burned in 2 seconds, and so on.

        You need to find the minimum time required to burn the complete binary tree.
        
Concept:- 1)We will maintain two maps, one for storing the parent, and other one for knowing that which node is burnt or not.
          2)Than recurivley we do it
          3)for a current node, we will check its parent,childs are burnt or not
          
Time - O(n)
Space - O(n)
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 void traversal(TreeNode *node,unordered_map<TreeNode*,bool> &burnt,TreeNode *par,
 unordered_map<TreeNode*,TreeNode*> &parent,int &val,TreeNode* &tar)
 {
     //base...
     if(node == NULL)
     return;
     
     burnt[node] = false; //creating a hash for all nodes
     parent[node] = par; //storing the parent 
     
     if(node->val == val) //if target is found, store its pointer or location
     tar = node;
     
     traversal(node->left,burnt,node,parent,val,tar); //left subtree
     traversal(node->right,burnt,node,parent,val,tar); //right subtree
 }
 
 int minTime(TreeNode *curr, unordered_map<TreeNode*,bool> &burnt,
 unordered_map<TreeNode*,TreeNode*> parent,int t,TreeNode *ori)
 {   
     burnt[curr] = true; // when some node is burnt , make it true
     
     int a = 0,b = 0,c = 0;
     
     //check parent...
     if(parent[curr] != NULL && burnt[parent[curr]] != true)
     {
         a = minTime(parent[curr],burnt,parent,t+1,ori);
     }
     
     //check left child...
     if(curr->left != NULL && burnt[curr->left] != true)
     {
         b = minTime(curr->left,burnt,parent,t+1,ori);
     }
     else if(curr->left == NULL) //if left child is NULL,this can be a answer
     b = t;
     
     //check right child...
     if(curr->right != NULL && burnt[curr->right] !=true)
     {
         c = minTime(curr->right,burnt,parent,t+1,ori);
     }
     else if(curr->right == NULL)
     c = t;
     
     return max({a,b,c});
 }
 
int Solution::solve(TreeNode* A, int B) {
    
    unordered_map<TreeNode*,bool> burnt; //for avoiding the re-burnt of node
    unordered_map<TreeNode*,TreeNode*> parent; //for storing the parent
    TreeNode* tar = NULL;
    
    traversal(A,burnt,NULL,parent,B,tar); //simple preorder traversal
    
    int ans = minTime(tar,burnt,parent,0,tar);
    
    return ans;
}
