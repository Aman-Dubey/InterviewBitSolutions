int Solution::colorful(int A){
    map<long long int ,int> mp;
    string s=to_string(A);
    int k=s.size();
    for(int i=0;i<k;i++)
    {
        long long int temp=1;
        for(int j=i;j<k;j++)
        {
            temp=temp*(s[j]-'0');
            if(mp.find(temp)==mp.end())
            mp[temp]=1;
            else return 0;
            
        }
    }
    return 1;
}
