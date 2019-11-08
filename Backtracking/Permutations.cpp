vector<vector<int>> ans1;
void solve(vector<int> &A,int start)
{
    if(start>=A.size())
    {
        ans1.push_back(A);
        return;
    }
    for(int i=start;i<A.size();i++)
    {
        swap(A[start],A[i]);
        solve(A,start+1);
        swap(A[start],A[i]);
    }
}
vector<vector<int> > Solution::permute(vector<int> &A) {
    ans1.clear();
    sort(A.begin(),A.end());
    solve(A,0);
    return ans1;
}

