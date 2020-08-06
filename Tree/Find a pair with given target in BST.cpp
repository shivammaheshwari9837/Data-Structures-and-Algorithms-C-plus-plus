/*

Ques :-Find a pair with given target in BST(Time - O(n) , space - O(H) or O(logn) )

Concept:- 1.)Just similar to array pair sum, where we apply to pointer algorithm
	2.)here we uses pointers, one for smaller elements(left pointer), and other(right pointer) for larger elements
	3.)We do inorder traversal for storing data in left pointer, and reverse inorder traversal for right pointer
  
  
  */
  
  bool isPairPresent(struct Node *root, int target)
{
//add code here.
    stack<Node*> s1,s2;
    
    Node *temp1 = root,*temp2 = root; //temp1 --->left pointer, temp2--->right pointer..
    
    while(1)
    {
        while(temp1) // going to extreme left for accessing the smallest possible value(ie. inorder traversal type)
        {
            s1.push(temp1);
            temp1 = temp1->left;
        }
        
        while(temp2) //going to extreme right for accessing the largest possible value(ie. reverse inorder traversal type)
        {
            s2.push(temp2);
            temp2 = temp2->right;
        }
        
        if(s1.empty() || s2.empty()) //is any stack is empty, no pair exits
        break;
        
        temp1 = s1.top();   //taking the minimum one
        temp2 = s2.top();   //picking the maximum one
        
        if((temp1->data + temp2->data) == target) //is equal 
        {
            if((temp1->data) == (temp2->data))  //is both are equal, means reaches to the same element ,false condition
            return false;
            
            return true;
        }
        else if((temp1->data + temp2->data) < target)  //if current sum < target, surely we have to increase the left pointer
        {
            s1.pop();
            temp1 = temp1->right;
            temp2 = NULL;
        }
        else       // if current sum > target, surely we have to decrease the right pointer
        {
            s2.pop();
            temp2 = temp2->left;
            temp1 = NULL;
        }
    }
    
    return false;
}
