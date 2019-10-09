int Solution::diffPossible(const vector<int> &A, int B) {
    int n=A.size();
    set<int> s;
    for(int i=0;i<n;i++)
    {
        if(s.find(A[i])!=s.end())
        {
            return 1;
        }
        else
        {
            s.insert(A[i]-B);
            s.insert(A[i]+B);
        }
    }
    return 0;
}

