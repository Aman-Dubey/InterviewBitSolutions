int Solution::nchoc(int A, vector<int> &B) {
    long long int ans=0;
    priority_queue<int> q;
    for(int i=0;i<B.size();i++) q.push(B[i]);
    while(A--)
    {
        if(q.size()==0) break;
        ans+=q.top();
        int k=q.top(); q.pop();
        q.push(floor(k/2));
    }
    return ans%1000000007;
}

