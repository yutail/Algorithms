// Preorder
vector<int> preorderTraversal(TreeNode *root) {
    vector<int> result;
    if (root == NULL)
        return result;
    stack<TreeNode *> s;
    s.push(root);
    
    while (!s.empty()) {
        TreeNode *curr = s.top();
        s.pop();
        result.push_back(curr->val);
        if (curr->right != NULL)
            s.push(curr->right);
        if (curr->left != NULL)
            s.push(curr->left);
    }
    return result;
}

// Inorder
vector<int> inorderTraversal(TreeNode *root) {
    vector<int> result;
    if (root == NULL)
        return result;
    stack<TreeNode *> s;
    TreeNode *curr = root;
    
    while (!s.empty() || curr) {
        if (curr != NULL) {
            s.push(curr);
            curr = curr->left;
        }
        else {
            curr = s.top();
            result.push_back(curr->val);
            s.pop();
            curr = curr->right;
        }
    }
    return result;
}

// Postorder
vector<int> postorderTraversal(TreeNode *root) {
    vector<int> result;
    if (!root)
        return result;
    stack<TreeNode *> s;
    TreeNode *prev = NULL;
    s.push(root);
    
    while (!s.empty()) {
        TreeNode *curr = s.top();
        if (!prev || prev->left==curr || prev->right==curr) {
            if (curr->left) {
                s.push(curr->left);
            }
            else if (curr->right) {
                s.push(curr->right);
            }
            else {
                result.push_back(curr->val);
                s.pop();
            }
        }
        else if (curr->left == prev) {
            if (curr->right) {
                s.push(curr->right);
            }
            else {
                result.push_back(curr->val);
                s.pop();
            }
        }
        else if (curr->right == prev) {
            result.push_back(curr->val);
            s.pop();
        }
        prev = curr;
    }
    return result;
}

// level Traversal
void levelTraversal(TreeNode *root)
{
    if (root == NULL)
        return;
    queue<TreeNode *> q;
    q.push(root);
    
    while (!q.empty()) {
        TreeNode *temp = q.front();
		q.pop();
        printf("%d\n", temp->data);
        if (temp->left != NULL)
            q.push(temp->left);
        if (temp->right != NULL)
            q.push(temp->right);
    }
}

