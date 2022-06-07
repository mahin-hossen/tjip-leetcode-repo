//MC: 0(1)
//TC: 0(n)

int lengthOfLongestSubstring(string s)
{
    int len = s.size();
    int cnt = 0, maxLength = 0;
    int L = 0, R = 0;
    vector<int>freq(256,0);

    while(R<len)
    {
        freq[s[R]]++;            
        if(freq[s[R]]>1)
        {
            while(freq[s[R]]>1)
            {                    
                freq[s[L]]--;
                L++;
            }
        }          
        R++;   
        maxLength = max(maxLength,R-L);
    }
    return maxLength;
}
