//MC: 0(n)
//TC: 0(n)
int romanToInt(string s) 
{      
    unordered_map<char,int> buckets {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
    
    int res = 0, index = 0;        
    int len = s.size();
    
    while(index<len-1)
    {
        if(s[index]=='I' && (s[index+1]=='V' || s[index+1]=='X')) res -= buckets[s[index]];
        else if(s[index]=='X' && (s[index+1]=='L' || s[index+1]=='C')) res -= buckets[s[index]];
        else if(s[index]=='C' && (s[index+1]=='D' || s[index+1]=='M')) res -= buckets[s[index]];
        else res += buckets[s[index]];                
        index++;
    }    

    res+= buckets[s[index]];   
    return res;
}
