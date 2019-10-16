int findans(TreeNode *A)
{
    if(!A) return INT_MAX;
    if(!A->left && !A->right) return 1;
    return 1+min(findans(A->left),findans(A->right));
}
int Solution::minDepth(TreeNode* A) {
    if(!A) return 0;
    if(!A->left && !A->right) return 1;
    return findans(A);
}
