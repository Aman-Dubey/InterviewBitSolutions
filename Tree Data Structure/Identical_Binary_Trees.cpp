int check(TreeNode *A,TreeNode *B)
{
    if(!A && !B) return 1;
    if((A==NULL && B!=NULL) || (B==NULL && A!=NULL))
    return 0;
    if(A->val!=B->val) return 0;
    if(A->left) return check(A->left,B->left);
    if(A->right) return check(A->right,B->right);
    return 1;
}
int Solution::isSameTree(TreeNode* A, TreeNode* B) {
    return check(A,B);
}
