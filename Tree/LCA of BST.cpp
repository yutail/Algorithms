// Recursive
TreeNode *LCARecursive(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (!root || !p || !q)
        return NULL;
    
    if (max(p->val, q->val) < root->val)
        return LCARecursive(root->left, p, q);
    if (min(p->val, q->val) > root->val)
        return LCARecursive(root->right, p, q);
    
    return root;
}

// Iterative
TreeNode *LCAIterative(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (!root || !p || !q)
        return NULL;
    
    while (root != NULL) {
        if (max(p->val, q->val) < root->val) {
            root = root->left;
        }
        else if (min(p->val, q->val) > root->val) {
            root = root->right;
        }
        else
            break;
    }
    return root;
}