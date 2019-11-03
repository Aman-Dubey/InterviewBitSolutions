set<vector<int>> s;
void solve(vector<int> A,int start,vector<int> v)
{
    s.insert(v);
    if(start>=A.size()) return;
    for(int i=start;i<A.size();i++)
    {
        v.push_back(A[i]);
        solve(A,i+1,v);
        v.pop_back();
    }
}
vector<vector<int> > Solution::subsetsWithDup(vector<int> &A) {
    sort(A.begin(),A.end());
    s.clear();
    vector<int> v;
    vector<vector<int>> ans;
    solve(A,0,v);
    for(auto i=s.begin();i!=s.end();i++) ans.push_back(*i);
    return ans;
}

