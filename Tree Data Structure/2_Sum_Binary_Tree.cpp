int Solution::t2Sum(TreeNode* A, int B)
{
    if(!A) return 0;
    stack<TreeNode*> l,r;
    TreeNode *L=A,*R=A;
    while(L)
    {
        l.push(L);
        L=L->left;
    }
    while(R)
    {
        r.push(R);
        R=R->right;
    }
    L=l.top(); R=r.top(); l.pop(); r.pop();
    int n1=L->val,n2=R->val;
    while(n1<n2)
    {
        if((n1+n2)==B) return 1;
        if((n1+n2)<B)
        {
            
            if(L->right==NULL && l.size())
            {
                L=l.top(); l.pop();
                n1=L->val;
            }
            else if(L->right!=NULL)
            {
                L=L->right;
                while(L)
                {
                    l.push(L);
                    L=L->left;
                }
                L=l.top(); l.pop();
                n1=L->val;
            }

        }
        else
        {
            if(R->left==NULL && r.size())
            {
                R=r.top(); r.pop();
                n2=R->val;
            }
            else if(R->left!=NULL)
            {
                R=R->left;
                while(R)
                {
                    r.push(R);
                    R=R->right;
                }
                R=r.top(); r.pop();
                n2=R->val;

            }
        }
        
    }
    return 0;
}

