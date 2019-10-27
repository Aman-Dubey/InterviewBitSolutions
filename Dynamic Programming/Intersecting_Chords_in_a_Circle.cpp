#define mod 1000000007

int Solution::chordCnt(int A)
{
    if(A<=0) return 0;
    long long int dp[A+1];
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=A;i++)
    {
        for(int j=0;j<i;j++)
        {
            dp[i]+=((dp[j]%mod)*(dp[i-j-1]%mod))%mod;
        }
    }
    return dp[A]%mod;
}
