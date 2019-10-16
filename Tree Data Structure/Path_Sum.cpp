 int t=0;
void findans(TreeNode *A,int B,int sum)
{
    if(A->left==NULL && A->right==NULL && sum==B)
    {
        t=1;
        return;
    }
     if(A->left) findans(A->left,B,sum+A->left->val);
     if(A->right) findans(A->right,B,sum+A->right->val);
    return;
    
}
int Solution::hasPathSum(TreeNode* A, int B) {
    t=0;
    if(!A || B==0) return 0;
    findans(A,B,A->val);
    return t;
}
