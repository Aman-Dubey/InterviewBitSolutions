long long int t=0;
void findans(TreeNode *A,vector<int> v)
{
    v.push_back(A->val);
    if(A->left==NULL && A->right==NULL)
    {
        long long int temp=0;
        for(int i=0;i<v.size();i++)
        temp=((temp*10) +v[i])%1003;
        t+=temp;
    }
    if(A->left) findans(A->left,v);
    if(A->right) findans(A->right,v);
    v.pop_back();
}
int Solution::sumNumbers(TreeNode* A) {
    t=0;
    if(!A) return 0;
    vector<int> v;
    findans(A,v);
    return t%1003;
}
