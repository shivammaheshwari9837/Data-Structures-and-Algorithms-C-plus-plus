/*

Ques:- see on gfg

Concept:- 1)if we obsevere, we simply cosidering a node to be in same diagonal on its just left right child, and the left child will be in the next diagonal too

Time - O(n)
Space - O(n)

*/

void helper(Node *root,unordered_map<int,int> &ump1,int hi)
{
    //base....
    if(root == NULL)
    return;
    
    ump1[hi] += root->data; //doing hashing according to that
    
    //for left subtree....increase the height...
    helper(root->left,ump1,hi+1);
    
    //for right subtree,to be in same diagonal,make height as same...
    helper(root->right,ump1,hi);
    
    return;
}

vector <int> diagonalSum(Node* root) {
    // Add your code here
    unordered_map<int,int> ump1;
    
    helper(root,ump1,0);
    
    vector<int> ans;
    int index = 0;
    
    while(ump1.find(index) != ump1.end())
    {
        auto it = ump1.find(index);
        ans.push_back(it->second);
        ++index;
    }
    
    return ans;
}

