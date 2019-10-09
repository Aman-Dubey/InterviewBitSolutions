 
 vector<int> v;
 void preorder1(TreeNode *A)
 {
     if(A==NULL) return;
     v.push_back(A->val);
     if(A->left) preorder1(A->left);
     if(A->right) preorder1(A->right);
 }
 
vector<int> Solution::preorderTraversal(TreeNode* A) {
    v.clear();
    preorder1(A);
    return v;
}

