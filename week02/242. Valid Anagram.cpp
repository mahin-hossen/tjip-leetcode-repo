//TC: 0(n)
//MC: 0(1)

bool isAnagram(string s, string t) 
{
    if(s.size()!=t.size()) return false;    
    int arr[256]={0};
    int lenS = s.size();

    for(int i=0;i<lenS;i++)
    {
        arr[s[i]-'0']++;
        arr[t[i]-'0']--;
    }

    for(int i=0;i<256;i++)
        if(arr[i]!=0) return false;

    return true;    
}  


//MC: 0(1)
//TC: nlogn

/* bool isAnagram(string s, string t) 
{
    if(s.size()!=t.size()) return false;
    sort(s.begin(),s.end());
    sort(t.begin(),t.end());
    
    for(int i=0;i<s.size();i++)
        if(s[i]!=t[i]) return false;
    
    return true;
} */

//MC: 0(n)
//TC: 0(n)
/* bool isAnagram(string s, string t) 
{
    if(s.size()!=t.size()) return false;    
    unordered_map<char,int> seen;
    
    for(auto &it : s) //0(n)
    {
        seen[it]++;
    }
    
    for(auto &it:t)//0(n)
    {
        if(seen[it]>0) seen[it]--;
        else return false;
    }
    
    for(auto &it:seen)
    {
        if(it.second>0) return false;
    }
    
    return true;               
} */