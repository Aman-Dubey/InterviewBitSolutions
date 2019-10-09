RandomListNode* Solution::copyRandomList(RandomListNode* A) {
    if(A==NULL) return NULL;
    RandomListNode *temp=A;
    map<RandomListNode*,RandomListNode*> mp;
    while(temp)
    {
        RandomListNode *t=new RandomListNode(temp->label);
        mp[temp]=t;
        temp=temp->next;
    }
    temp=A;
    RandomListNode *head=mp[A],*curr=mp[A];
    while(temp)
    {
        curr->next=mp[temp->next];
        curr->random=mp[temp->random];
        temp=temp->next;
        curr=curr->next;
    }
    return head;
}
