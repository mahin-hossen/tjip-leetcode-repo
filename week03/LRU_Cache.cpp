//MC:0(n)
//TC:0(1)
//where n is maxCapacity of LRU

list<int> lru;
unordered_map<int,list<int>::iterator> address;
unordered_map<int,int> kv;
int maxCap;

LRUCache(int capacity) 
{
    maxCap = capacity;
}

int get(int key)
{
    if(kv.count(key)==0) return -1;
    updateLRU(key);
    return kv[key];
}

void put(int key, int value) 
{
    if(kv.count(key)==0 && kv.size()==maxCap) evict();
    updateLRU(key);           
    kv[key]=value;        
}

void updateLRU(int key)
{
    if(kv.count(key))  lru.erase(address[key]);
    lru.push_front(key);
    address[key]=lru.begin();
}

void evict()
{        
    int lastElement = lru.back();
    lru.pop_back();
    address.erase(lastElement);
    kv.erase(lastElement);       
}