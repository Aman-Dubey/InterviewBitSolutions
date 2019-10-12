stack<TreeNode*> s;
BSTIterator::BSTIterator(TreeNode *root)
{
    while(s.size())
    s.pop();
    TreeNode *temp=root;
    while(temp)
    {
        s.push(temp);
        temp=temp->left;
    }
}
bool BSTIterator::hasNext() {
    if(s.size()==0)
    return false;
    return true;

}
int BSTIterator::next() {
    int n=s.top()->val;
    TreeNode *L=s.top(); s.pop();
    L=L->right;
    while(L)
    {
        s.push(L);
        L=L->left;
    }
    return n;
}
