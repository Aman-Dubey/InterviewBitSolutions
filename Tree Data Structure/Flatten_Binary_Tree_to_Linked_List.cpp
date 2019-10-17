TreeNode* Solution::flatten(TreeNode* A) {
    TreeNode *temp=A;
    while(temp)
    {
        if(temp->left)
        {
            TreeNode *t=temp->left;
            while(t->right)
            t=t->right;
            t->right=temp->right;
            temp->right=temp->left;
            temp->left=NULL;
            temp=temp->right;
        }
        else
        temp=temp->right;
    }
    return A;
}
