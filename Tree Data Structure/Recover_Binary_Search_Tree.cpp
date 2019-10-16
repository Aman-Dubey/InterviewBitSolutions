//Method 1 using not extra space... Morris Theorem is used here...

vector<int> Solution::recoverTree(TreeNode* A) {
    vector<int> v;
    if(!A) return v;
    int a=-1,b=-1,c=-1,d=-1,cn=-1,e=1;
    TreeNode *cur=A,*pre=A;
    while(cur!=NULL)
    {
        if(cur->left==NULL)
        {
            //cout<<cur->val<<" ";
            a=b;
            b=cur->val;
            if(a!=-1)
            {
                if(b<a && e)
                {
                    e=0;
                    c=a;
                    cn=b;
                }
                else if(a>b)
                {
                    d=b;
                    break;
                }
                
            }
            cur=cur->right;
        }
        else
        {
            pre=cur->left;
            while(pre->right!=NULL && pre->right!=cur)
            pre=pre->right;
            if(pre->right==NULL)
            {
                pre->right=cur;
                cur=cur->left;
            }
            else
            {
                pre->right=NULL;
                //cout<<cur->val<<" ";
                 a=b;
            b=cur->val;
            if(a!=-1)
            {
                if(b<a && e)
                {
                    e=0;
                    c=a;
                    cn=b;
                }
                else if(a>b)
                {
                    d=b;
                    break;
                }
                
            }
                cur=cur->right;
            }
        }
    }
    v.push_back(c);
    if(d==-1)
    {
        v.push_back(cn);
    }
    else
    {
        v.push_back(d);
    }
    sort(v.begin(),v.end());
    return v;
}



/*
 //Method 2...extra space is used in recursion stack


vector<int> ans;
void fill(TreeNode *A)
{
    if(!A) return;
    if(A->left) fill(A->left);
    ans.push_back(A->val);
    if(A->right) fill(A->right);
    delete(A);
}
vector<int> Solution::recoverTree(TreeNode* A) {
    ans.clear();
    vector<int> v;
    if(!A) return v;
    fill(A);
    int a=0,b=-1,c=1;
    for(int i=0;i<ans.size()-1;i++)
    {
        if(ans[i]>ans[i+1] && c)
        {
            c=0;
            a=i; continue;
        }
        if(ans[i+1]<ans[i])
        {
            b=i+1;
            break;
        }
    }
    v.push_back(ans[a]);
    if(b==-1)
    v.push_back(ans[a+1]);
    else
    v.push_back(ans[b]);
    sort(v.begin(),v.end());
    return v;
    
}
*/



