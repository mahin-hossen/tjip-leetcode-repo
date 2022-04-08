void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
{
    int nums1Iterator = m-1, nums2Iterator = n-1, zeroIterator = m+n-1;
    for(;nums1Iterator>=0 && nums2Iterator>=0;)
    {
        if(nums1[nums1Iterator]<=nums2[nums2Iterator])
        {
            nums1[zeroIterator]=nums2[nums2Iterator];
            nums2Iterator--,zeroIterator--;
        } 
        else
        {
            nums1[zeroIterator]=nums1[nums1Iterator];
            nums1Iterator--,zeroIterator--;
        } 
    }  
    while(nums1Iterator>=0)
    {
        nums1[zeroIterator] = nums1[nums1Iterator];
        nums1Iterator--,zeroIterator--;
    } 
    while(nums2Iterator>=0)
    {
        nums1[zeroIterator] = nums2[nums2Iterator];
        nums2Iterator--,zeroIterator--;
    }

}
