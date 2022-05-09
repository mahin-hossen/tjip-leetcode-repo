//MC: 0(n)
//TC: 0(n)

bool isIsomorphic(string s, string t, int iterationCount = 0) 
{
    unordered_map<char,char> buckets;
    for(int i=0;i<s.size();i++)
    {
        if(buckets.count(s[i]) && buckets[s[i]]!=t[i]) 
            return false;
        buckets[s[i]]=t[i];
    }
    
    if(iterationCount==0) 
        return isIsomorphic(t,s,1);
    
    return true;
} 
