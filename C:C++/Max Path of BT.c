/*
* For root node, first check two subtrees and figure out the path with maximum sum in each subtree
* (and the path must contains the root node). More precisely, we can compare root->val, root->val +
* leftsubtree, root->val + rightsubtree.
*
* But this is not enough since the maximum path might contains two subtrees. We have to compute the
* value of root->val + leftsubtree + rightsubtree as well. The problem is, we cannot directly return
* this value since this path cannot go to upper nodes anymore. So we also use another global variable
* to store the maximum sum in each recursion, and update this variable once we find any path with
* larger sum.
*/


int maxPathSum(TreeNode *root) {
    int csum;
    int maxSum = INT32_MIN;
    maxPathSumHelper(root, csum, maxsum);
    return maxSum;
}

int maxPathSumHelper(TreeNode *root, int &csum, int &maxSum) {
    if (root == NULL) {
        csum = 0
        return;
    }
    int lsum = 0, rsum = 0;
    maxPathSumHelper(root->left, lsum, maxSum);
    maxPathSumHelper(root->right, rsum, maxSum);
    
    csum = max(root->val, max(root->val+lsum, root->val+rsum));
    maxSum = max(maxSum, max(csum, root->val+lsum+rsum));   
    
}

