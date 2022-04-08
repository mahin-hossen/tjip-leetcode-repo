/* int singleNumber(vector<int>& nums) 
{
    if(nums.size()==1) return nums[0];

    sort(nums.begin(),nums.end());    
    for(int i=0;i<nums.size()-1;i+=2)
    {
        if(nums[i]!=nums[i+1]) return nums[i];
    }
    return nums.back();
} */


int singleNumber(vector<int>& nums) 
{
    int ans = 0;

    for(int i=0;i<nums.size();i++)
    {
        ans^=nums[i];
    }        
        
    return ans;
} 
