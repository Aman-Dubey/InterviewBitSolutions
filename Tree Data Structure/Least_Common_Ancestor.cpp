void find(TreeNode *A,int B,int C,int &p)
{
    if(!A) return;
    if(A->left) find(A->left,B,C,p);
    if(A->val==B || A->val==C) p++;
    if(A->right) find(A->right,B,C,p); 
}
TreeNode* findans(TreeNode *A,int B,int C)
{
    if(A==NULL) return NULL;
    if(A->val==B || A->val==C) return A;
    TreeNode *L=findans(A->left,B,C);
    TreeNode *R=findans(A->right,B,C);
    if(L && R) return A;
    return L?L:R;

}
int Solution::lca(TreeNode* A, int B, int C)
{
    if(!A) return -1;
    int p=0;
    find(A,B,C,p);
    if(p==0) return -1;
    if(p==1 && B!=C) return -1;
    TreeNode *root=findans(A,B,C);
    return root->val;
}
