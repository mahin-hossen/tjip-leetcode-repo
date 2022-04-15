//TC(N)
//MC(N)
int trap(vector<int>& height)
{
    int left = 0, right = height.size()-1;
    int leftMax = 0, rightMax = 0;
    int totalArea = 0;

    while(left<right)
    {
        if(height[left]>leftMax) leftMax = height[left];
        if(height[right]>rightMax) rightMax = height[right];

        if(height[left]<height[right])
        {
            totalArea+=leftMax-height[left];
            left++;
        }
        else if(height[left]>=height[right])
        {
            totalArea+=rightMax-height[right];
            right--;	
        }
    } 

    return totalArea; 
}

