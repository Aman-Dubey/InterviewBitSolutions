vector<int> Solution::twoSum(const vector<int> &A, int B) {
    vector<int> v;
    map<int,int> mp;
    for(int i=0;i<A.size();i++)
    {
        int k=B-A[i];
        if(mp.find(A[i])!=mp.end())
        {
            
            v.push_back(mp[A[i]]+1);
            v.push_back(i+1);
            return v;
        }
        if(mp.find(k)==mp.end())
        mp[k]=i;
        
    }
    return v;
}

