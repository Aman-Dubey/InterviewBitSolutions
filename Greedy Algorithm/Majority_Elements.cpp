/*

// Method 1

int Solution::majorityElement(const vector<int> &A) {
    map<int,int> mp;
    for(int i=0;i<A.size();i++)
    {
        if(mp.find(A[i])==mp.end()) mp[A[i]]=1;
        else mp[A[i]]++;
    }
    for(auto i=mp.begin();i!=mp.end();i++)
    {
        if(i->second > (A.size()/2)) return i->first; 
    }
    return 0;
}

*/

// Method 2

int Solution::majorityElement(const vector<int> &A) {
    int count=1,index=0;
    for(int i=1;i<A.size();i++)
    {
        if(A[i]==A[index])
        count++;
        else count--;
        if(count==0)
        { index=i; count=1;}
    }
    return A[index];
}

