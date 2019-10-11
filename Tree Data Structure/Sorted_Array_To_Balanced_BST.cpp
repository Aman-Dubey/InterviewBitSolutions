TreeNode * make(const vector<int> &A,int start,int end)
{
    if(start>end) return NULL;
    int k=(start+end)/2;
    TreeNode *root=new TreeNode(A[k]);
    root->left=make(A,start,k-1);
    root->right=make(A,k+1,end);
    return root;
}
TreeNode* Solution::sortedArrayToBST(const vector<int> &A)
{
    if(A.size()==0)
    return NULL;
    return make(A,0,A.size()-1);
}
