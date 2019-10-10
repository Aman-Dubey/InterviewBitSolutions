int Solution::lengthOfLongestSubstring(string A) {
    int n=A.size(),s=0,e=0,ans=0,res=0;
    if(n<=1) return n;
    int temp[125]={0};
    for(int i=0;i<n;i++)
    {
        int k=A[i];
        if(temp[k]==0)
        {
            temp[k]++;
            ans++;
            res=max(ans,res);
        }
        else
        {
            while(1)
            {
                if(s==n) break;
                int e=A[s];
                if(temp[k]==0) break;
                else
                {
                    temp[e]--; ans--;
                }
                s++;
            }
            temp[k]++; ans++;
            res=max(ans,res);
        }
    }
    
    
    return res;
}

