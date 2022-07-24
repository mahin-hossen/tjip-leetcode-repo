/*
TC : 0(n*m) 
MC : 0(n*m) //if all the rooms are valid
            // here n is row of the grid
                and m is col of the grid
*/

static constexpr int INF = 2147483647;
static constexpr int dirs[5] = {-1,0,1,0,-1};

void wallsAndGates(vector<vector<int>>& rooms)
{
    int n = rooms.size();
    int m = rooms[0].size();    
    queue<pair<int,int>> gates;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(rooms[i][j]==0)
            {
                gates.push({i,j});
            }
                
        }
    }   
      
    while(!gates.empty())
    {
        auto room = gates.front();
        gates.pop();

        for(int i=0;i<4;i++)
        {
            int X = room.first+dirs[i];
            int Y = room.second+dirs[i+1];
            if(X>=0 && Y>=0 && X<n && Y<m && rooms[X][Y]==INF)
            {
                gates.push({X,Y});
                rooms[X][Y] = rooms[room.first][room.second] + 1;
            }
        }

    }
}