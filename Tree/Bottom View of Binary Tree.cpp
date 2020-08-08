/*

Ques:- Given a binary tree, print the bottom view from left to right.
A node is included in bottom view if it can be seen when we look at the tree from bottom.

                      20
                    /    \
                  8       22
                /   \        \
              5      3       25
                    /   \      
                  10    14

For the above tree, the bottom view is 5 10 3 14 25.
If there are multiple bottom-most nodes for a horizontal distance from root, then print the later one in level traversal. For example, in the below diagram, 3 and 4 are both 
the bottommost nodes at horizontal distance 0, we need to print 4.

                      20
                    /    \
                  8       22
                /   \     /   \
              5      3 4     25
                     /    \      
                 10       14

For the above tree the output should be 5 10 4 14 25.

Concept:- 1.)This question uses concept similar to --->vertical level order traversal of a binary tree
          2.)First we try to traverse the tree in preorder traversal
          3.)Than we make two varibles for every node, first--->depth node and second-->value
          4.)For every node, for left subtree we decrease the postion by 1, and for right subtree we increase by 1
          5.)and replce whenever we encounter the same postion element , while taking into cosideration the most depth element
          
Time - O(nlogn), space - O(height of tree)

*/


void helper(Node *root,map<int,pair<int,int> > &m1,int dis,int depth)
{
    if(root == NULL)
    return;
    
    helper(root->left,m1,dis - 1,depth + 1); // for left subtree, decrease position by 1
    
    if(m1.find(dis) != m1.end()) //if same position element exits
    {
        auto p = m1.find(dis);
        if(depth >= (p->second.second)) // if current root element >= existing element
        {
            m1[dis] = {root->data,depth}; // repalce it
        }
    }
    else // not found
    {
        m1[dis] = {root->data,depth};
    }
    
    helper(root->right,m1,dis + 1,depth + 1);  // for right subtree, increase  position by 1
    
    return;
}

// Method that returns the bottom view.
vector <int> bottomView(Node *root)  // start here...........
{
   // Your Code Here
   map<int,pair<int,int>> m1;  //map{positon(left/right subtree with respect to root) , pair(data , depth of current node) }
   vector<int> ans;
   
   helper(root,m1,0,0); // (root,map,position,depth)
   
   for(auto i=m1.begin();i!=m1.end();++i)
   ans.push_back(i->second.first);
   
   return ans;
}

