set<vector<int>> s;
void solve(vector<int> A,int end,int start,vector<int> v,int sum,int st)
{
    if(st>sum) return;
    if(st==sum)
    {
        sort(v.begin(),v.end());
        s.insert(v);
    }
    for(int i=start;i<end;i++)
    {
        v.push_back(A[i]);
        solve(A,end,i+1,v,sum,st+A[i]);
        v.pop_back();
    }
    
}
vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
   vector<int> v;
   s.clear();
   vector<vector<int>>ans;
   solve(A,A.size(),0,v,B,0);
   for(auto i=s.begin();i!=s.end();i++) ans.push_back(*i);
   return ans;
}

