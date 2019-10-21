vector<int> Solution::dNums(vector<int> &A, int B) {
    vector<int> v;
    if(A.size()==0) return v;
    map<int,int> mp;
    for(int i=0;i<B;i++)
    {
        if(mp.find(A[i])==mp.end())
        mp[A[i]]=1;
        else
        mp[A[i]]++;
    }
    int j=0,ans=mp.size();
    v.push_back(mp.size());
    for(int i=B;i<A.size();i++)
    {
        mp[A[j]]--;
        if(mp[A[j]]==0) ans--;
        j++;
        if(mp.find(A[i])==mp.end())
        {
            ans++;
            mp[A[i]]=1;
        }
        else
        {
            if(mp[A[i]]==0)
            {
                mp[A[i]]=1;
                ans++;
            }
            else
            mp[A[i]]++;
        }
        v.push_back(ans);
    }
    return v;
}

