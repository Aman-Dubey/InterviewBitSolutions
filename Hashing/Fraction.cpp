string Solution::fractionToDecimal(int A, int B) {
    string s;
    long long int sign=1;
    long long int ss=A,bb=B;

    long long int r=ss*bb;
    if(r < 0) sign=-1;
    ss=abs(ss); bb=abs(bb);
    long long int k=ss/bb;
    long long int mo=ss%bb;
    if(k==0 && mo==0)
    {
        s+='0'; return s;
    }
    if(sign==-1)
    s+='-';
    s+=to_string(k);
    if(mo==0)
    return s;
    s+='.';
    long long int j=0;
    string temp;
    map<long long int,long long int> mp;
    mp[mo]=j; j++;
    while(1)
    {
        k=mo*10;
        mo=k%bb;
        k/=bb;
        temp+=to_string(k);
        if(mo==0)
        break;
        if(mp.find(mo)!=mp.end())
        {
            long long int ee=mp[mo];
            string gg,hh,jj;
            for(long long int q=ee;q<temp.size();q++)
            gg+=temp[q];
            for(long long int q=0;q<ee;q++)
            hh+=temp[q];
            temp=jj;
            temp+=hh; temp+='('; temp+=gg;
            temp+=')';
            break;
        }
        else
        mp[mo]=j;
        j++;
        
    }
    
    s+=temp;
    return s;
}

