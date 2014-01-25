// O(nlogn)  T(n) = T(n/2) + O(n)
TreeNode *sortedListToBST(ListNode *head) {
    if (head == NULLL)
        return NULL;
    if (head->next == NULL) {
        TreeNode *curr = new TreeNode(head->val);
        return curr;
    }
    
    ListNode *slow = head;
    ListNode *fast = head;
    ListNode *prev = NULL;
    while (fast!=NULL && fast->next!=NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next = NULL;
    TreeNode *root = new TreeNode(slow->val);
    
    root->left = sortedListToBST(head);
    root->right = sortedListToBST(slow->next);

    return root;
}

// O(n)  Bottom-up
TreeNode *sortedListToBST(ListNode *head) {
    int n = getLength(head);
    
    return convertHelper(&head, n);
}

TreeNode *convertHelper(ListNode **headRef, int n) {
    if (n <= 0)
        return NULL;
    
    TreeNode *left = convertHelper(headRef, n/2);
    
    TreeNode *root = new TreeNode((*headRef)->val);
    root->left = left;
    
    *headRef = (*headRef)->next;
    
    TreeNode *right = convertHelper(headRef, n-n/2-1);
    root->right = right;
    
    return root;
}

int getLength(ListNode *head) {
    if (head == NULL)
        return 0;
    int count = 0;
    ListNode *curr = head;
    
    while (curr != NULL) {
        curr = curr->next;
        count++;
    }
    return count;
}

