int Solution::isValidSudoku(const vector<string> &A) {
    int temp[9][9]={0};
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(A[i][j]!='.')
            {
                int r=-1;
                for(int k=0;k<9;k++)
                {
                    if(A[i][k]==A[i][j])
                    r++;
                }
                if(r) return 0;
                r=-1;
                for(int k=0;k<9;k++)
                {
                    if(A[k][j]==A[i][j])
                    r++;
                }
                if(r)
                return 0;
                r=(i/3)*3 + j/3;
                int e=A[i][j]-'0'-1;
                if(temp[r][e])
                return 0;
                else
                temp[r][e]=1;
            }
        }
    }
    return 1;
}

