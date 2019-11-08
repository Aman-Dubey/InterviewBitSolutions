vector<int> Solution::grayCode(int A) {
    vector<int> v;
    for(int i=0;i<pow(2,A);i++)
    {
        v.push_back(i^(i/2));
        cout<<v[i]<<" ";
    }
    return v;
}

