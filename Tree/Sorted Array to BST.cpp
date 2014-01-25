// O(n)
TreeNode *sortedArrayToBST(vector<int> &num) {
    return convertHelper(num, 0, num.size()-1);
}

TreeNode *convertHelper(vector<int> &num, int lo, int hi) {
    if (lo <= hi) {
        int mid = (lo + hi) / 2;
        TreeNode *root = new TreeNode(num[mid]);
        root->left = convertHelper(num, lo, mid-1);
        root->right = convertHelper(num, mid+1, hi);
        return root;
    }
    else
        return NULL;
}

