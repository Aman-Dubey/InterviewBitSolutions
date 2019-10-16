TreeNode * findans(TreeNode *A)
{
    if(!A) return NULL;
    findans(A->left);
    findans(A->right);
    TreeNode *temp=A->left;
    A->left=A->right;
    A->right=temp;
    return A;
}
TreeNode* Solution::invertTree(TreeNode* A) {
    if(!A) return A;
    return findans(A);
}
