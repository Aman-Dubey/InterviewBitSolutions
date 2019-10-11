int check(TreeNode *A)
 {
     if(!A) return 0;
    int l=1+check(A->left);
    int r=1+check(A->right);
    if(abs(r-l)>1) return INT_MIN;
    if(l<0 || r<0) return INT_MIN;
    return max(l,r);
 }
int Solution::isBalanced(TreeNode* A) {
    int k=check(A);
    if(k<0) return 0;
    return 1;
}
