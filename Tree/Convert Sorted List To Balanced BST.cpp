/*

Ques:- Given the head of a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
       For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
       
Concept:- 1)Here we break our current List from middle recursivley(similar we do in Merge Sort)
          2)Making node as root,and recurring to further left and right child 
          
Time - O(n* log n)
Space - O(n)
*/

    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL)
            return NULL;
        
        if(head->next == NULL)
        {
            TreeNode *t1 = new TreeNode(head->val);
            return t1;
        }
        
        ListNode *slow = head,*fast = head,*prev = NULL;
        
        while(fast != NULL && fast->next != NULL) //finding the middle of list using slow-fast pointer
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        prev->next = NULL;
        
        TreeNode *curr = new TreeNode(slow->val);
        curr->left = sortedListToBST(head);
        curr->right = sortedListToBST(slow->next);
        
        return curr;
    }
