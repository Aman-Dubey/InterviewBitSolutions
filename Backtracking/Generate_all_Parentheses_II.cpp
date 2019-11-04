vector<string> v;
void solve(int A,int open,int close,string s)
{
    if(close==A) v.push_back(s);
    if(open<A)
    {
        s+="(";
        solve(A,open+1,close,s);
        s.pop_back();
    }
    if(open>close)
    {
        s+=")";
        solve(A,open,close+1,s);
        s.pop_back();
    }
}
vector<string> Solution::generateParenthesis(int A) {
    v.clear();
    string s;
    solve(A,0,0,s);
    return v;
}

