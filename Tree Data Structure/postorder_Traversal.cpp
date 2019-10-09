 vector<int> v;
void post(TreeNode *A)
{
    if(!A) return;
    if(A->left) post(A->left);
    if(A->right) post(A->right);
    v.push_back(A->val);
}
vector<int> Solution::postorderTraversal(TreeNode* A) {
    v.clear();
    post(A);
    return v;
}
