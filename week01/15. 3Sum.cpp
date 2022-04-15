vector<vector<int>> threeSum(vector<int>& nums) 
{
   sort(nums.begin(),nums.end());
   vector<vector<int>> triplets;

    for(int i=0;i<(int)nums.size()-1;i++)
    {
       int target = - nums[i];
       int left = i+1;
       int right = (int)nums.size()-1;       
       
       while(left<right)
       {
            int sum = nums[left]+nums[right];
            if(sum==target ) 
            {
                int l = nums[left], r = nums[right];
                while(left+1<right && nums[left+1]==l) left++;//remove duplicates
                while(left<right-1 && nums[right-1]==r) right--;//remove duplicates

                triplets.push_back({nums[left],nums[right],nums[i]});
                left++,right--;
            }              
            else if(sum<target) left++;
            else right--; 
       }
       while(i<(int)nums.size()-1 && nums[i]==nums[i+1]) i++;//remove dulpicates
   } 
   return triplets;
}
