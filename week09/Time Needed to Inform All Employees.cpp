/*
TC : 0(n)       //here n is number of employees
MC : 0(n)
*/
vector<vector<int>>adjacentNodes;
int totalMinutes(int headID,vector<int>& informTime)
{
    int minutes = 0;
    for(auto subordinate : adjacentNodes[headID])
    {        
        minutes = max(minutes,totalMinutes(subordinate,informTime));
    }
    return minutes+informTime[headID];
}

int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) 
{    
    adjacentNodes.clear();
    adjacentNodes.resize(n+1);
    for(int i=0;i<n;i++)
    {
        if(manager[i]!=-1)
            adjacentNodes[manager[i]].push_back(i);
    }

    return totalMinutes(headID,informTime);
}



/**********without adjacent nodes***********/
/*
TC : 0(n)  // n is the number of employees
MC : 0(H) // here H is depth of the tree
*/
/*

int sumOfMinutes(int headID, vector<int>& manager, vector<int>& informTime) 
{
    if(manager[headID]!=-1)
    {
        informTime[headID] += sumOfMinutes(manager[headID],manager,informTime);
        manager[headID] = -1;    
    }   
    return informTime[headID];
    
}
    
int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) 
{
    int minutes = 0;
    for(int i=0;i<n;i++)
    {
        minutes = max(minutes,sumOfMinutes(i,manager,informTime));
    }
    return minutes;
}
*/