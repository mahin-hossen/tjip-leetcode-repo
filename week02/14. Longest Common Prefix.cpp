//MC: 0(1)
//TC: 0(n*m)
string longestCommonPrefix(vector<string>& strs) 
{
    string prefix = "";

    for(int i=0;i<strs[0].size();i++)
    {
        for(auto &str:strs)
        {
            if(strs[0][i]==str[i])  continue;
            else return prefix;
        }
        prefix+=strs[0][i];
    }
    return prefix;
}