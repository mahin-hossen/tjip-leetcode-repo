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
	bool oneExist = 0;
	int maxElement = nums.size()-1;
	int len = nums.size();

	for(int i=0;i<len;i++)
	{
		if(nums[i]==1) oneExist = 1;
		else if(nums[i]>maxElement || nums[i]<1) nums[i] = 1;
	}
		
	if(!oneExist) return 1;

	for(int i = 0;i<len;i++)
	{
		nums[abs(nums[i])]= -nums[nums[i]];
	}
		
	for(int i=0;i<len;i++)
	{
		if(nums[i]>0) return i+1;
	}

	return 0;
}


int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    vector<int>v{1,1};
    cout<<firstMissingPositive(v)<<endl;
    
}