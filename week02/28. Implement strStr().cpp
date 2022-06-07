//MC 0(n)
//TC 0(n)

vector<long long>prefixHaystack, power;
int MOD = 1000000007;
int base = 26;
void preprocess(string &haystack)
{
    int len = haystack.size();
    prefixHaystack[0] = haystack[0];
    power[0]=1;

    for(int i=1;i<len;i++) //0(n)
    {
        prefixHaystack[i]=(prefixHaystack[i-1]*base+haystack[i])%MOD;
        power[i]=(power[i-1]*base)%MOD;
    }    
}

long long getRangeHash(int L,int R)//0(1)
{
    int x1 = prefixHaystack[R];
    int x2 = L == 0 ? 0 : (prefixHaystack[L-1]*power[R-L+1])%MOD;
    return (x1-x2+MOD)%MOD;
}
long long generateHash(string &str)//0(m)
{
    long long h = 0;
    for(auto &s:str)
    {
        h = h*base+s;
        h %= MOD;
    }
    return h;
}
int strStr(string haystack,string needle)
{
    int lb = needle.size();
    int la = haystack.size();
    
    prefixHaystack.resize(la+1,0);
    power.resize(la+1,1);

    preprocess(haystack);
    long long nH = generateHash(needle);

    for(int i=0;i<la-lb+1;i++)
    {
        if(getRangeHash(i,i+lb-1)==nH)
            return i;
    }
    return -1;
}