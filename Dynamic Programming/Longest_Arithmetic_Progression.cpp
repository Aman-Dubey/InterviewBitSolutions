int Solution::solve(const vector<int> &A) {
    int n=A.size(),res=0;
    pair<int,set<int>> dp[n];
    if(n<=2) return n;
    dp[0].first=1; dp[0].second.insert(0);
    dp[1].first=2; dp[1].second.insert(A[1]-A[0]);
    for(int i=2;i<n;i++)
    {
        int ans=1;
        for(int j=i-1;j>=0;j--)
        {
            dp[i].second.insert(A[i]-A[j]);
            if(dp[j].second.find(A[i]-A[j])!=dp[j].second.end())
            {
                ans=max(ans,dp[j].first);
            }
        }
        dp[i].first=ans+1;
        res=max(res,dp[i].first);
    }
    return res;
}

