TreeLinkNode *get(TreeLinkNode *root)
{
    struct TreeLinkNode *temp=root->next;
    
    while(temp!=NULL)
    {
        if(temp->left)
            return temp->left;
        else if(temp->right)
            return temp->right;
        else 
            temp=temp->next;
    }
    
    return NULL;
}

void Solution::connect(TreeLinkNode* A) {
    struct TreeLinkNode *temp=NULL;
    
    if(A==NULL)
        return;
        
    A->next=NULL;    
    
    if(A->left==NULL && A->right==NULL)
        return;
        
    while(A!=NULL)
    {
        temp=A;
        
        while(temp!=NULL)
        {
            if(temp->left)
            {
                if(temp->right)
                    temp->left->next=temp->right;
                else 
                    temp->left->next=get(temp);
            }
            
            if(temp->right)
                temp->right->next=get(temp);
            
            temp=temp->next;    
        }
        
        if(A->left)
            A=A->left;
        else if(A->right)
            A=A->right;
        else
            A=get(A);
    }
}




/*



// METHOD 2



void Solution::connect(TreeLinkNode* A) {
    if(!A) return;
    queue<TreeLinkNode*> q;
    q.push(A); q.push(NULL);
    while(q.size())
    {
        TreeLinkNode *temp=q.front(); q.pop();
        if(temp==NULL)
        {
            if(q.size()==0)
            break;
            q.push(NULL);
        }
        else
        {
            temp->next=q.front();
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }
}


*/
