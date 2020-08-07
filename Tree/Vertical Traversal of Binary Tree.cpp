/*

Ques:- Given a Binary Tree, print the vertical traversal of it starting from the leftmost level to the rightmost level.
If there are multiple nodes passing through a vertical line, then they should be printed as they appear in level order traversal of the tree.

Concept:- 1.)We will traversal every node in a level order traversal node first and maintain a distance(for every node) ie. the deviation from root
          2.)From current node , if we visit left subtree---> subtract 1, and if we visit right subtree---> add 1.
          3.)we maintain a map<int,vector<int> >  , where map.first will be according to the deviation form root
          
 Time - O(nlogn) , space -O(n)

*/


void helper(Node* root,map<int,vector<int> >&m1)
{
    if(root == NULL)
    return;
    
    queue<pair<int,Node*> >q1; // for level order traverasl , first  = distance from root, second = current root
    q1.push({0,root});
    
    while(!q1.empty()) // simple level order traversal.......
    {
        int siz = q1.size();
        
        for(int i=0;i<siz;++i)
        {
            Node *temp = q1.front().second;
            int dis = q1.front().first;
            
            m1[dis].push_back(temp->data);
            
            if(temp->left != NULL)
            q1.push({dis - 1,temp->left}); // for left subtree, subtract 1.......
            
            if(temp->right != NULL)
            q1.push({dis + 1,temp->right}); // for right subtree, add 1
            
            q1.pop();
        }
    }
}

// root: root node of the tree
vector<int> verticalOrder(Node *root)
{
    //Your code here
    map<int,vector<int> >m1;  // map.first = distance of a node,  map.second = vector of that particula distance in level order traversal too
    
    helper(root,m1); //call
    
    vector<int> ans;
    
    for(auto i = m1.begin();i!=m1.end();++i)
    {
        vector<int> p = i->second;
        for(int j=0;j<p.size();++j)
        ans.push_back(p[j]);
    }
    return ans;
    
}
