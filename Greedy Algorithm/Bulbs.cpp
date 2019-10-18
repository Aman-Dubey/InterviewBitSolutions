int Solution::bulbs(vector<int> &A) {
    int n=A.size(),O=0,Z=0,F=1,ans=0;
    for(int i=0;i<n;i++)
    {
        if(A[i]==1) O++;
        else Z++;
    }
    //F=1 means zero is in Z else in O;
    for(int i=0;i<n;i++)
    {
        if(F==1)
        {
            if(A[i]==1)
            {
                O--;
                continue;
            }
            else
            {
                Z--;
                ans++;
                swap(Z,O);
                F=0;
            }
        }
        else
        {
            if(A[i]==0)
            {
                Z--;
                continue;
            }
            else
            {
                O--;
                ans++;
                swap(O,Z);
                F=1;
            }
        }
    }
    return ans;
}

