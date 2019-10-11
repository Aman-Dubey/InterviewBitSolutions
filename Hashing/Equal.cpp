vector<int> Solution::equal(vector<int> &A) {
    int n=A.size();
    vector<int> v;
    set<vector<int>> s;
    if(n<4) return v;
    for(int i=0;i<n-3;i++)
    {
        for(int j=i+1;j<n-1;j++)
        {
            
            int sum=A[i]+A[j];
            map<int,int> mp;
            for(int k=i+1;k<n;k++)
            {
                if(s.size())
            {
                vector<int> tt=*s.begin();
                if(tt[0]<i) break;
                if(tt[1]<j) break;
            }
                if(k==j) continue;
                if(mp.find(A[k])!=mp.end())
                {
                    vector<int> vv;
                    vv.push_back(i);
                    vv.push_back(j);
                    vv.push_back(mp[A[k]]);
                    vv.push_back(k);
                    s.insert(vv);
                }
                else
                {
                    if(mp.find(sum-A[k])==mp.end())
                    mp[sum-A[k]]=k;
                    else
                    {
                        mp[sum-A[k]]=min(mp[sum-A[k]],k);
                    }
                    

                }
            }
        }
    }
    if(s.size()==0)
    return v;
    v=*s.begin();
    return v;
}

