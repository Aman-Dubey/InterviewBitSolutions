#define mod 1000000007
long long  int v[101][101]={0};
long long int dp[101]={0};
int t=0;
long long  int ncr(long long  int n,long long  int r)
{
    if(n==r||r==0)
    return 1;
    if(v[n][r])
    return v[n][r];
    return v[n][r]=(ncr(n-1,r-1)%mod + ncr(n-1,r)%mod)%mod;
}
void find()
{
    for(int A=3;A<101;A++)
    {
        int h=log2(A+1) -1;
        int b=pow(2,h) -1;
        int r=A-1-(2*b);
        int t=r/(b+1);
        int r1=r-(t*(r-b-1));
        int r2=r-r1;
        dp[A]=((((ncr(A-1,b+r1)%mod)*dp[b+r1])%mod)*dp[b+r2])%mod;
    }
}
int Solution::solve(int A) {
    if(t==0)
    {
        dp[0]=0; dp[1]=dp[2]=1;
        t=1;
        find();
    }
    return dp[A]%1000000007;
}

// link for formula is :   http://mathworld.wolfram.com/Heap.html

