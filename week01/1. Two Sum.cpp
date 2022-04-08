/* vector<int> twoSum(vector<int>& nums, int target) 
{
    map<int,vector<int>> m;
    vector<int> v;

    for(int i=0;i<nums.size();i++)
    {
        m[nums[i]].push_back(i);
    }
    
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]+nums[i]==target && m[target-nums[i]].size()>1)
        {
            v.push_back(m[target-nums[i]][0]);
            v.push_back(m[target-nums[i]][1]);
            break;
        }
        else if(nums[i]+nums[i]!=target && m.count(target-nums[i]))
        {
            v.push_back(i);
            v.push_back(m[target-nums[i]][0]);
            break;
        }
    }
    return v;
} */

vector<int> twoSum (vector<int> & nums, int target){
	
	map<int,int>seen;

    for(int i=0;i<nums.size();i++)
	{
	    if(seen.count(target-nums[i])){
            return {i,seen[target-nums[i]]};
        }
        seen[nums[i]]=i;
    }
    return {};
}
