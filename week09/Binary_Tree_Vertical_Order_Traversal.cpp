/*
TC :  0((N+E)logN)
MC :  0(N)  
                //where N is number of nodes
                        E is number of edges
*/

vector<vector<int>> verticalOrder(TreeNode* root) 
{
    map<int,vector<int>> order;
    queue<pair<int,TreeNode*>> nodes;
    if(root) nodes.push({0,root});
    
    while(!nodes.empty())
    {
        auto node = nodes.front();
        nodes.pop();
        
        order[node.first].push_back(node.second->val);
        if(node.second->left)   nodes.push({node.first-1,node.second->left});
        if(node.second->right)   nodes.push({node.first+1,node.second->right});
    }
    
    vector<vector<int>> vertOrder;
    for(auto element : order)
    {
        vertOrder.push_back(element.second);
    }
    
    return vertOrder;
}