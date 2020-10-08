/*

Ques:- You are given a binary tree in which each node contains an integer value.

        Find the number of paths that sum to a given value.

        The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).

        The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.
        
Concept:- 1)code Link:- https://leetcode.com/problems/path-sum-iii/discuss/141424/Python-step-by-step-walk-through.-Easy-to-understand.-Two-solutions-comparison.-%3A-)

Time - O(n)
Space - O(n)

*/

void helper(TreeNode *root,int &sum,int pathSum,unordered_map<int,int> &oldSum,int &ans)
    {
        //base..
        if(root == NULL)
            return;
        
        pathSum += root->val;
        
        if(oldSum.find(pathSum - sum) != oldSum.end())
        {
            ans += oldSum[pathSum - sum];
        }
        
        ++oldSum[pathSum];
        helper(root->left,sum,pathSum,oldSum,ans);
        helper(root->right,sum,pathSum,oldSum,ans);
        --oldSum[pathSum];
    }
    
    int pathSum(TreeNode* root, int sum) {
        if(root == NULL)
            return 0;
        
        unordered_map<int,int> oldSum;
        
        ++oldSum[0];
        int ans = 0;
        
        helper(root,sum,0,oldSum,ans);
        
        return ans;
    }
