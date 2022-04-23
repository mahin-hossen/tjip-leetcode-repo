//MC:0(1)
//TC:0(n*m)
int numMatchingSubseq(string s, vector<string>& words) 
{
    int cnt = 0, found;
    vector<int>seen[256];

    for(int i=0;i<s.size();i++)
    {
        int temp = s[i]-'0';
        seen[s[i]-'0'].push_back(i);        
    }

    for(auto word:words)
    {
        found = true;
        int lastIndex = -1;
        for(int i=0;i<word.size();i++)
        {
            auto it = upper_bound(seen[word[i]-'0'].begin(),seen[word[i]-'0'].end(),lastIndex);            
            if(it==seen[word[i]-'0'].end())
            {
                found=false;
                break;
            }
            lastIndex = *it;
        }
        if(found) cnt++;
    }
    return cnt;
}