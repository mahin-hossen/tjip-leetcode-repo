#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
const int MAX = 1e5+1;
int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int kx[] = {1,1,2,2,-1,-1,-2,-2};
int ky[] = {2,-2,1,-1,2,-2,1,-1};
/* int findKthLargest(vector<int>& nums, int k) 
{
    sort(nums.begin(),nums.end());
    auto it = nums.rbegin();
    advance(it,k-1);
    return *it;
} */
int findKthLargest(vector<int>& nums, int k) 
{
    sort(nums.begin(),nums.end());
    auto it = nums.rbegin();
    advance(it,k-1);
    return *it;
}
int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    vector<int>v{3,2,1,5,6,4};
    int k = 2;
    findKthLargest(v,k);
    
}