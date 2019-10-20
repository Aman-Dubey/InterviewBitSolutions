ListNode* Solution::mergeKLists(vector<ListNode*> &A)
{
    if(A.size()==0) return NULL;
    int n=A.size();
    priority_queue<pair<int,ListNode*>> p;
    for(int i=0;i<n;i++)
    {
        ListNode *temp=A[i];
        while(temp)
        {
            p.push(make_pair(temp->val,temp));
            temp=temp->next;
        }
    }
    ListNode *head=(p.top()).second; p.pop();
    head->next=NULL;
    while(p.size())
    {
        ListNode *tt=(p.top()).second; p.pop();
        tt->next=head;
        head=tt;
    }
    return head;

}
