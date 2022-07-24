/*
TC : 0(n*m)         //here, n = row of the grid
                           m = col of the grid

MC : 0(n*m)
*/

static constexpr int dirs[5] = {-1,0,1,0,-1};
int n, m;
void traverseIslands(int x,int y,vector<vector<char>>& grid)
{
    grid[x][y] = '0';
    for(int i=0;i<4;i++)
    {
        int X = x+dirs[i];
        int Y = y+dirs[i+1];
        if(X>=0 && Y>=0 && X<n && Y<m && grid[X][Y]=='1')//unvisited
        {
            traverseIslands(X,Y,grid);                
        }
    }
}
int numIslands(vector<vector<char>>& grid) 
{
    n = grid.size();
    m = grid[0].size();
    int island_count = 0;
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]=='1')//unvisited
            {
                traverseIslands(i,j,grid);
                island_count++;
            }
                
        }
    }
    
    return island_count;
}