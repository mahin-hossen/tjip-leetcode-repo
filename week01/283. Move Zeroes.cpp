void moveZeroes(vector<int>& nums) 
{
    int zeroIndex = - 1;

    for(int i=0;i<nums.size();i++)
    {
        if(zeroIndex<0 && nums[i]==0) zeroIndex=i;
        else if(zeroIndex>=0 && nums[i]!=0)
        {
            swap(nums[i],nums[zeroIndex]);
            zeroIndex++;
        }
    }
    
    return;
}
