//TC: nlogn
//MC: 0(n)
static bool cmp(string &s1,string &s2)
{
    return s1+s2>s2+s1;
}
string largestNumber(vector<int>& nums)
{
    vector<string> store;
    for(auto &num:nums)
    {
        store.push_back(to_string(num));
    }
    sort(store.begin(),store.end(),cmp);
    
    string str;
    
    for(auto &it:store)
    {
        str+=it;
    }   
    
    if(str[0]=='0') return "0";    
    
    return str;
}