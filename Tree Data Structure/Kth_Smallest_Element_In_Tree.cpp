int t=0,ans;
void findans(TreeNode *A,int B)
{
    if(!A) return;
    if(A->left) findans(A->left,B);
    t++;
    if(t==B) {ans=A->val; return;}
    if(A->right) findans(A->right,B);
}
int Solution::kthsmallest(TreeNode* A, int B) {
    t=0;
    findans(A,B);
    return ans;
}
