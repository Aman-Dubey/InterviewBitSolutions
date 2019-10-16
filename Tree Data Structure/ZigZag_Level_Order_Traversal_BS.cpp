vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    vector<vector<int>> v;
    if(!A) return v;
    queue<TreeNode*> q;
    q.push(A); q.push(NULL);
    vector<int> vv;
    int k=0;
    while(q.size())
    {
        TreeNode *temp=q.front(); q.pop();
        if(temp==NULL)
        {
            k++;
            if(k%2==0)
            reverse(vv.begin(),vv.end());
            v.push_back(vv);
            vv.clear();
            if(q.size()!=0)
            q.push(NULL);
            else break;
                
        }
        else
        {
            vv.push_back(temp->val);
            if(temp->left!=NULL) q.push(temp->left);
            if(temp->right!=NULL) q.push(temp->right);
            
        }
    }
    return v;
}

