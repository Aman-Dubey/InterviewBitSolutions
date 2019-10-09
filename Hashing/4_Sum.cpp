vector<vector<int> > Solution::fourSum(vector<int> &A, int B) {
    sort(A.begin(),A.end());
    vector<vector<int>> v;
    if(A.size()<=3) return v;
    int n=A.size(),tt=0;
    for(int i=0;i<n-3;i++)
    {
        for(int j=i+1;j<n-2;j++)
        {
            int sum=B-A[i]-A[j];
            
            map<int,int> mp;
            for(int k=j+1;k<n;k++)
            {
                int temp=sum-A[k];
                if(mp.find(A[k])!=mp.end())
                {
                    vector<int> a;
                    a.push_back(A[i]);
                    a.push_back(A[j]); a.push_back(A[k]);
                    a.push_back(A[mp[A[k]]]);
                    
                    sort(a.begin(),a.end());
                    if(find(v.begin(),v.end(),a)==v.end())
                    v.push_back(a);
                }
                else
                mp[temp]=k;
            }
            
        }
    }
    sort(v.begin(),v.end());
    return v;
    
}

