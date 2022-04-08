int majorityElement(vector<int> &nums)
{
	int cnt=0, value = 0;
	for(int i=0;i<nums.size();i++)
	{
		if(nums[i]==value) cnt++;
		else
		{
			if(cnt==0) value = nums[i], cnt++;
			else cnt--;
		}
	}
	return value;
}
