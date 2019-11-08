long long int fact(int x)
{
    if(x>18) return -1;
    if(x==0) return 1;
    long long int ans=1;
    for(int i=2;i<=x;i++)
    ans*=i;
    return ans;
}
string Solution::getPermutation(int A, int B) {
    string ans;
    int arr[A+1],s=A,k=B;
    for(int i=0;i<=A;i++) arr[i]=i;
    arr[0]=-1;
    while(1)
    {
        long long int x=0;
        int temp=0;
        for(int i=1;i<=A;i++)
        {
            if(arr[i]!=-1 && s>0)
            {
                temp=i;
                if(fact(s-1)==-1)
                {
                    ans+=to_string(i);
                    s--;
                    arr[i]=-1;
                    if(i==A) return ans;
                    continue;
                }
                x+=fact(s-1);
                if(x>=k)
                break;
            }
        }
        arr[temp]=-1;
        if(temp==0) break;
        if(x==k)
        {
            ans+=to_string(temp);
            for(int i=A;i>0;i--)
            {
                if(arr[i]!=-1)
                ans+=to_string(i);
            }
            break;
        }
        k-=(x-fact(s-1));
        ans+=to_string(temp);
        s--;
    }
    return ans;
}

