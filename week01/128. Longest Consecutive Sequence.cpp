//MC:0(n)
//TC:0(n)
int longestConsecutive(vector<int>& nums)
{    
    unordered_set<int> checker(nums.begin(),nums.end());    
    int cnt=0, mxCount = 0 ;
    
    for(int i=0;i<nums.size();i++)
    {
        if(checker.count(nums[i]-1)) continue;
        
        int num = nums[i], cnt = 1; 

        while(checker.count(++num))
        {
            cnt++;			
        }
        mxCount = max(mxCount,cnt);	
    }
    return mxCount;
}

