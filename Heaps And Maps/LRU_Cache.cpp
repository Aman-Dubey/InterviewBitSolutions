map<int,int> mp;
deque<int> v;
int maxi=0;
LRUCache::LRUCache(int capacity) {
    maxi=capacity;
    mp.clear();
    v.clear();
}

int LRUCache::get(int key) {
    if(mp.find(key)==mp.end()) return -1;
    auto it=v.begin();
    while(*it!=key) it++;
    v.erase(it);
    v.push_front(key);
    return mp[key];
}

void LRUCache::set(int key, int value) {
    if(mp.find(key)==mp.end())
    {
        if(v.size()==maxi)
        {
            int k=v.back();
            v.pop_back();
            mp.erase(k);
        }
         
    }
    else
    {
      auto it=v.begin();
      while(*it!=key) it++;
      v.erase(it);
     
    }
    mp[key]=value;
    v.push_front(key);
}

