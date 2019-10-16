int findans(TreeNode *A)
{
    int l=0,r=0;
    if(A->left) l=1+findans(A->left);
    if(A->right) r=1+findans(A->right);
    return max(l,r);
}
int Solution::maxDepth(TreeNode* A) {
    if(!A) return 0;
    return findans(A)+1;
}
