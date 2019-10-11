int findindex(vector<int> &A,int start,int end)
{
    int index=start;
    for(int i=start;i<=end;i++)
    {
        if(A[i]>A[index])
        index=i;
    }
    return index;
}
TreeNode * make(vector<int> &A,int start,int end)
{
    if(start>end) return NULL;
    int k=findindex(A,start,end);
    TreeNode *root=new TreeNode(A[k]);
    root->left=make(A,start,k-1);
    root->right=make(A,k+1,end);
    return root;
}
 
TreeNode* Solution::buildTree(vector<int> &A) {
    if(A.size()==0) return NULL;
    return make(A,0,A.size()-1);
}
