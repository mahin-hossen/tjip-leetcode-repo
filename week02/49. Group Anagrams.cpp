//TC : 0(n)
//MC : 0(n)

unsigned long long getHash(string str)
{
    unsigned long long h = 1;
    for(auto &c : str)
    {
        h *= 257 + (c-'a');
    }
    return h;
}
vector<vector<string>> groupAnagrams(vector<string>& strs) 
{
    unordered_map<unsigned long long,vector<string>>buckets;
    
    for(auto &str : strs)
    {        
        buckets[getHash(str)].push_back(str);
    }

    vector<vector<string>> anagrams;
    for(auto &bucket:buckets)
    {
        anagrams.push_back(bucket.second);
    }
    return anagrams;
}

//TC : nlogn
//MC : 0(n)
/* 
vector<vector<string>> groupAnagrams(vector<string>& strs) 
{
    unordered_map<string,vector<string>>buckets;
    
    for(auto &str : strs)
    {
        auto val = str;
        sort(val.begin(),val.end());
        buckets[val].push_back(str);
    }

    vector<vector<string>> anagrams;
    for(auto &bucket:buckets)
    {
        anagrams.push_back(bucket.second);
    }
    return anagrams;
}
 */