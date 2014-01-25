// There are three cases: (1) the node has no left or right child
// (2) the node has exactly one child (left or right)
// (3) the node has two children

// Iterative
void deleteNode(TreeNode *root, TreeNode *target) {
    if (root == NULL || target == NULL)
        return;
    
    TreeNode *parent = NULL;
    TreeNode *curr = root;
    
    while (curr != NULL) {
        if (curr->val > target->val) {
            parent = curr;
            curr = curr->left;
        }
        else if (curr->val < target->val) {
            parent = curr;
            curr = curr->right;
        }
        else
            break;
    }
    if (curr == NULL)
        return;
    
    if (target->left==NULL && target->right==NULL) {
        if (parent == NULL)
            root = NULL;
        else if (parent->left == target)
            parent->left = target->right;
        else
            parent->right = target->right;
        
    }
    else if (target->left == NULL) {
        if (parent == NULL)
            root = root->right;
        else if (parent->left == target)
            parent->left = target->right;
        else
            parent->right = target->right;
    }
    else if (target->right == NULL) {
        if (parent == NULL)
            root = root->left;
        else if (parent->left == target)
            parent->left = target->left;
        else
            parent->right = target->left;
    }
    else {
        TreeNode *next = target->right;
        TreeNode *p;
        while (next->left != NULL) {
            p = next;
            next = next->left;
        }
        next->left = target->left;
        next->right = target->right;
        p->left = NULL;
        if (parent == NULL)
            root = next;
        else if (parent->left == target)
            parent->left = next;
        else
            parent->right = next;
    }
}

