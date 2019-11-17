bool check(int A,vector<string> &v,int x,int y)
{
    string s[A];
    int k=0;
    for(int i=0;i<A;i++)
    {
        string temp;
        for(int j=0;j<A;j++)
        {temp+=v[k]; k++;}
        s[i]=temp;
    }
    for(int i=0;i<A;i++)
    {
        if(i!=x)
        {
            if(s[i][y]!='.')
            return false;
        }
    }
    for(int i=0;i<A;i++)
    {
        if(i!=y)
        {
            if(s[x][i]!='.')
            return false;
        }
    }
    int X=x,Y=y;
    while(x<A && x>=0 && y<A && y>=0)
    {
        if(x!=X && y!=Y)
        if(s[x][y]!='.') return false;
        x--;y--;
    }
    x=X; y=Y;
    while(x<A && x>=0 && y<A && y>=0)
    {
        if(x!=X && y!=Y)
        if(s[x][y]!='.') return false;
        x--;y++;
    }
    x=X; y=Y;
    while(x<A && x>=0 && y<A && y>=0)
    {
        if(x!=X && y!=Y)
        if(s[x][y]!='.') return false;
        x++;y++;
    }
    x=X; y=Y;
    while(x<A && x>=0 && y<A && y>=0)
    {
        if(x!=X && y!=Y)
        if(s[x][y]!='.') return false;
        x++;y--;
    }
    return true;
    
}
void solve(vector<vector<string>> &ans,int A,int x,int y,vector<string> v,int queen)
{
    if(queen==A) { ans.push_back(v); return;}
    if(queen>A) return;
        for(int j=y;j<A;j++)
        {
            if(check(A,v,x,j))
            {
                v[(A*x)+j]="Q";
                solve(ans,A,x+1,0,v,queen+1);
                v[(A*x)+j]=".";
            }
        }
}
vector<vector<string> > Solution::solveNQueens(int A) {
   vector<vector<string>> ans,res;
   vector<string> v;
   if(A==1)
   {
       v.push_back("Q");
       ans.push_back(v);
       return ans;
   }
   if(A<=3) return ans;
   for(int i=0;i<(A*A);i++) v.push_back(".");
   solve(ans,A,0,0,v,0);
   for(int m=0;m<ans.size();m++)
   {
       vector<string> rr;
       for(int i=0;i<A;i++)
       {
           string temp;
           for(int j=0;j<A;j++)
           {
               temp+=ans[m][(A*i)+j];
           }
           rr.push_back(temp);
       }
       res.push_back(rr);
   }
   return res;
}

