int Solution::seats(string A) {
    int n=A.size(),p=0;
    for(int i=0;i<n;i++)
    {
        if(A[i]=='x') p++;
    }
    int pos=0,temp=0;
    for(int i=0;i<n;i++)
    {
        if(A[i]=='x')
        temp++;
        if(temp==((p+1)/2))
        {
            pos=i;
            break;
        }
    }
    int j=pos-1;
    long long ans=0;
    for(int i=0;i<pos;i++)
    {
        if(A[i]=='.') continue;
        while(A[j]=='x')
        j--;
        if(j<0 || i>=j) break;
        A[j]='x';
        A[i]='.';
        ans+=abs(j-i);
    }
    j=pos+1;
    for(int i=n-1;i>pos;i--)
    {
        if(A[i]=='.') continue;
        while(A[j]=='x')
        j++;
        if(j<0 || i<=j) break;
        A[j]='x';
        A[i]='.';
        ans+=abs(j-i);
    }
    return ans%10000003;
}

