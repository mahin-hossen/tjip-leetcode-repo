//TC: 0(N^2)
//MC: 0(N)

int BASE = 1000000007;
long long getSerializedValue(pair<int,int> val)
{
    return 1LL*val.first*BASE+val.second;
}

int minAreaRect(vector<vector<int>>& points) 
{       
    unordered_map<long long,int> buckets;
    for(auto point : points)
    {
        buckets[getSerializedValue({point[0],point[1]})]=1;
    }
    
    int minArea = INT_MAX;
    for(int i=0;i<(int)points.size()-1;i++)
    {              
        for(int j=i+1;j<points.size();j++)
        {
            int x1 = points[i][0];
            int y1 = points[i][1];
            int x3 = points[j][0];
            int y3 = points[j][1];        
            
            if(x1==x3 || y3==y1) continue;
            if(buckets.count(getSerializedValue({x1,y3})) && buckets.count(getSerializedValue({x3,y1})))
            {
                int currArea = abs(x3-x1)*abs(y3-y1);
                minArea = min(currArea,minArea);
            }
        }
    }
    
    return minArea == INT_MAX ? 0 : minArea;             
}