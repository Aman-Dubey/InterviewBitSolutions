bool pali(string s)
{
    string temp=s;
    reverse(s.begin(),s.end());
    if(temp==s) return true;
    return false;
}
set<vector<string>> s;
void solve(string A,int start,vector<string> v)
{
    int n=0;
    for(int i=0;i<v.size();i++)
    {
        for(int j=0;j<v[i].size();j++)
        n++;
    }
    if(n>A.size()) return;
    if(n==A.size()) s.insert(v);
    for(int i=start;i<A.size();i++)
    {
        for(int j=i;j<A.size();j++)
        {
            string temp;
            for(int k=i;k<=j;k++)
            temp+=A[k];
            if(pali(temp))
            {
                v.push_back(temp);
                solve(A,j+1,v);
                v.pop_back();
            }
        }
    }
}
vector<vector<string> > Solution::partition(string A) {
    s.clear();
    vector<vector<string>> ans;
    vector<string> v;
    solve(A,0,v);
    for(auto i=s.begin();i!=s.end();i++) ans.push_back(*i);
    return ans;
}

