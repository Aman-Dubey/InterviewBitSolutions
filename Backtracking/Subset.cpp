vector<vector<int>> v;
void solve(vector<int> &A,vector<int> temp,int start)
{
    v.push_back(temp);
    for(int i=start;i<A.size();i++)
    {
        temp.push_back(A[i]);
        solve(A,temp,i+1);
        temp.pop_back();
    }
}

vector<vector<int> > Solution::subsets(vector<int> &A) {
    v.clear();
    sort(A.begin(),A.end());
    vector<int> temp;
    solve(A,temp,0);
    return v;
}

