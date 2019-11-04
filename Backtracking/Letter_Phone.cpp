vector<string> ans;
map<char,string> mp=
{
    
    {'0',"0"},
    {'1',"1"},
    {'2',"abc"},
    {'3',"def"},
    {'4',"ghi"},
    {'5',"jkl"},
    {'6',"mno"},
    {'7',"pqrs"},
    {'8',"tuv"},
    {'9',"wxyz"}
    
};

void solve(string A,string s,int start,int end)
{
    if(s.size()==A.size()) ans.push_back(s);
    if(s.size()>A.size()) return;
    for(int i=start;i<end;i++)
    {
        for(int j=0;j<mp[A[i]].size();j++)
        {
            s+=(mp[A[i]])[j];
            solve(A,s,i+1,end);
            string t;
            for(int f=0;f<s.size()-1;f++)
            t+=s[f];
            s=t;
        }
    }
}
vector<string> Solution::letterCombinations(string A) {
    string s="";
    ans.clear();
    solve(A,s,0,A.size());
    return ans;
}

