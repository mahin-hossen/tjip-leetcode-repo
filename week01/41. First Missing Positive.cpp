/* int firstMissingPositive(vector<int>& nums) 
{
    unordered_set<int>seen(nums.begin(),nums.end());
    for(int i=1;i<=nums.size()+1;i++)
    {
        if(!seen.count(i)) return i;
    }        
    return 0;
}

 */
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
const int MAX = 1e5+1;
int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int kx[] = {1,1,2,2,-1,-1,-2,-2};
int ky[] = {2,-2,1,-1,2,-2,1,-1};

int firstMissingPositive(vector<int>& nums) 
{
	for(int i=0;i<nums.size();i++)
	{
		while(nums[i]!=i+1 && nums[i]!=-1)
		{
			if(nums[i]<1 || nums[i]>nums.size())
				nums[i]=-1;
			else if(nums[i]==nums[nums[i]-1]) break;
            else 
                swap(nums[i],nums[nums[i]-1]);//0(1)
		}
	}
	for(int i=0;i<nums.size();i++)//0(n)
	{
		if(nums[i]<0) return i+1;
	}

	return nums.size()+1;
}

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    vector<int>v{1,1};
    cout<<firstMissingPositive(v)<<endl;
    
}