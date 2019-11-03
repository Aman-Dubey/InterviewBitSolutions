set<vector<int>> s;
void solve(int A,int B,vector<int> v,int start)
{
    if(v.size()==B) s.insert(v);
    if(v.size()>B) return ;
    for(int i=start;i<=A;i++)
    {
        v.push_back(i);
        solve(A,B,v,i+1);
        v.pop_back();
    }
}
vector<vector<int> > Solution::combine(int A, int B) {

    s.clear();
    vector<int> v;
    solve(A,B,v,1);
    vector<vector<int>> ans;
    for(auto i=s.begin();i!=s.end();i++)
    ans.push_back(*i);
    return ans;
}

