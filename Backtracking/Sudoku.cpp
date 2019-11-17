bool check(vector<vector<int>> &v,int x,int y,int value)
{
    if(value==0) return false;
    for(int i=0;i<9;i++)
    if(v[i][y]==value) return false;
    for(int i=0;i<9;i++)
    if(v[x][i]==value) return false;
    x=x-x%3;
    y=y-y%3;
    for(int i=x;i<x+3;i++)
    {
        for(int j=y;j<y+3;j++)
        {
            if(v[i][j]==value) return false;
        }
    }
    return true;
}
vector<vector<int>> ans;
void solve(vector<vector<int>> &v,int x,int y)
{
    int X=-1,Y=-1;
    for(int i=0;i<9;i++)
    {
        int f=0;
        for(int j=0;j<9;j++)
        {
            if(v[i][j]==0)
            {
                X=i; Y=j; f=1; break;
            }
        }
        if(f) break;
    }
    if(X==-1 && Y==-1)
    {
        ans=v; return;
    }
    for(int i=1;i<=9;i++)
    {
        if(check(v,X,Y,i))
        {
            v[X][Y]=i;
            solve(v,X,Y);
            v[X][Y]=0;
        }
    }
}
void Solution::solveSudoku(vector<vector<char> > &A) {
    ans.clear();
    vector<vector<int>> v;
    vector<int> temp;
    for(int i=0;i<9;i++) temp.push_back(0);
    for(int i=0;i<9;i++) v.push_back(temp);
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(A[i][j]=='.')
            {
                v[i][j]=0;
            }
            else
            v[i][j]=A[i][j]-'0';
        }
    }
    solve(v,0,0);
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        A[i][j]=ans[i][j]+'0';
    }
}

