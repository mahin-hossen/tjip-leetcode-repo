//MC: 0(n)
//TC: 0(n) for count
//    0(1) for add

unordered_map<long long,int> points;
int BASE = 1000000007;

long long getSerializedValue(pair<int,int> val)
{
    return (1LL*val.first*BASE)+val.second;
}

DetectSquares() 
{
    points.clear();
}

void add(vector<int> point) 
{
    points[getSerializedValue({point[0],point[1]})]++;
}


int count(vector<int> qpoint) 
{
    int total = 0;
    
    for(auto point:points)
    {
        int x2 = qpoint[0];
        int x4 = point.first/BASE;
        int y2 = qpoint[1];
        int y4 = point.first%BASE;
        
        if(y2==y4 || abs(y2-y4)!=abs(x2-x4)) continue;
        if(points.count(getSerializedValue({x2,y4}))  && points.count(getSerializedValue({x4,y2})))
        {
            total+= points[getSerializedValue({x2,y4})]*points[getSerializedValue({x4,y2})]*points[getSerializedValue({x4,y4})];
        }
            
    }
    
    
    return total;
}