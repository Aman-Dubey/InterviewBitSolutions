vector<vector<int>> v;
void findans(TreeNode *A,int B,int sum,vector<int> vv)
{
    vv.push_back(A->val);
    if(A->left==NULL && A->right==NULL && sum==B)
    v.push_back(vv);
    if(A->left) findans(A->left,B,sum+A->left->val,vv);
    if(A->right) findans(A->right,B,sum+A->right->val,vv);
    vv.pop_back();
}
vector<vector<int> > Solution::pathSum(TreeNode* A, int B) {
    v.clear();
    if(!A) return v;
    vector<int> vv;
    findans(A,B,A->val,vv);
    return v;
}
