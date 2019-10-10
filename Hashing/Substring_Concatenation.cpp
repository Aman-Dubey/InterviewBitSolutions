vector<int> Solution::findSubstring(string A, const vector<string> &B) {
    vector<int> v;
    int a=A.size(),b=B.size(),bb=B[0].size();
    if(a==0 || b==0 || bb==0)
    return v;
    map<string,int> mp;
    for(int i=0;i<b;i++)
    {
        if(mp.find(B[i])==mp.end())
        mp[B[i]]=1;
        else
        mp[B[i]]++;
    }

    int total=b*bb;
    for(int i=0;i<a+1-total;i++)
    {
        int k=0;
        map<string,int> mp1;
        for(int j=i;j<i+total;j+=bb)
        {
            if(j>=a) break;
            string temp;
            for(int t=j;t<j+bb;t++)
            {
                temp+=A[t];
            }
            if(mp.find(temp)==mp.end())
            break;
            else
            {
                if(mp1.find(temp)==mp1.end())
                {
                    mp1[temp]=1;
                    k++;
                }
                else
                {
                    if(mp1[temp]>=mp[temp])
                    break;
                    else
                    {
                        mp1[temp]++;
                        k++;
                    }
                    
                }
            }
        }
        if(k==b)
        v.push_back(i);
    }
    return v;
}

