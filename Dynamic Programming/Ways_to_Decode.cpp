bool isvalid(string A,int s,int e)
{
    if(A[s]=='0') return false;
    int ans=A[s]-'0';
    ans=ans*10 + (A[e]-'0');
    if(ans<=26) return true;
    return false;
}
bool is0atend(string A,int s,int e)
{
    int k=A[s]-'0';
    k*=10;
    if(k<=26) return true;
    return false;
}
int Solution::numDecodings(string A) {
    int n=A.size();
    if(n==0 || A[0]=='0') return 0;
    if(n==1) return 1;
    if(A[1]=='0')
    {
        if(is0atend(A,0,1)==false)
        return 0;
    }
    int e=1,ans=1;
    if(isvalid(A,0,1) && A[1]!='0') ans=2;
    for(int i=2;i<n;i++)
    {
        if(A[i]=='0')
        {
            if(A[i-1]=='0') return 0;
            if(is0atend(A,i-1,i)==false) return 0;
            else
            {
                ans=e;
                e=0;
            }
        }
        if(isvalid(A,i-1,i))
        {
            int tt=ans;
            ans+=e;
            e=tt;
        }
        else
        {
            e=ans;
        }
    }
    return ans;
}

