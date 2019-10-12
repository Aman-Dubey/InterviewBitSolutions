int find(vector<int> &A,int start,int end,int x)
{
    for(int i=start;i<=end;i++)
    {
        if(A[i]==x) return i;
    }
}
TreeNode * findans(vector<int> &A,vector<int> &B,int start,int end,int &p)
{
    if(start>end) return NULL;
    int k=find(A,start,end,B[p]);
    TreeNode *temp=new TreeNode(B[p++]);
    temp->left=findans(A,B,start,k-1,p);
    temp->right=findans(A,B,k+1,end,p);
    return temp;
}
 
 
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    if(A.size()!=B.size() || A.size()==0) return NULL;
    int k=0;
    return findans(B,A,0,B.size()-1,k);
}
