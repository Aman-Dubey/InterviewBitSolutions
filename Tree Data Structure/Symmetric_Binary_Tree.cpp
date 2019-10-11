int Solution::isSymmetric(TreeNode* A) {
    
    
    if(!A) return 1;
    queue<TreeNode*> l,r;
    l.push(A); l.push(NULL);
    r.push(A); r.push(NULL);
    while(l.size())
    {
        TreeNode *t1=l.front(),*t2=r.front();
        l.pop(); r.pop();
        if(!t1 && !t2)
        {
            if(l.size()==0) break;
            l.push(NULL); r.push(NULL);
        }
        else
        {
            if(t1->val!=t2->val) return 0;
            if(t1->left) l.push(t1->left);
            if(t1->right) l.push(t1->right);
            if(t2->right) r.push(t2->right);
            if(t2->left) r.push(t2->left);
        }
    }
    return 1;
}
