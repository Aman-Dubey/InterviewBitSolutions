int Solution::longestSubsequenceLength(const vector<int> &A) {
    int is[A.size()],ds[A.size()],ans=0,n=A.size();
    for(int i=0;i<n;i++)
    {
        int temp=0;
        for(int j=0;j<i;j++)
        {
            if(A[j]<A[i])
            temp=max(temp,is[j]);
        }
        is[i]=temp+1;
    }
    
    for(int i=n-1;i>=0;i--)
    {
        int temp=0;
        for(int j=n-1;j>i;j--)
        {
            if(A[i]>A[j])
            temp=max(temp,ds[j]);
        }
        ds[i]=temp+1;
    }
    for(int i=0;i<n;i++)
    ans=max(ans,is[i]+ds[i]);
    if(ans==0) return 0;
    return ans-1;
}
