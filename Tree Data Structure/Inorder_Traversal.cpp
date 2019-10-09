vector<int> v;
 void inorder(TreeNode *A)
 {
     if(A==NULL) return;
     if(A->left) inorder(A->left);
     v.push_back(A->val);
     if(A->right) inorder(A->right);
 }
vector<int> Solution::inorderTraversal(TreeNode* A) {
    v.clear();
    inorder(A);
    return v;
}
