/*
TC : 0(N) 
MC : 0(N)   //Here, N is number of elements in the array
*/
void traversePreorder(vector<int>& preorder,int &currIdx,int L,int R)
{    
    if(currIdx==preorder.size()) return;
    
    int V = preorder[currIdx];
    if(V<L || V>R) return;
    currIdx++;
    
    traversePreorder(preorder,currIdx,L,V-1);
    traversePreorder(preorder,currIdx,V+1,R);
}
bool verifyPreorder(vector<int>& preorder)
{
    int currIdx = 0;
    traversePreorder(preorder,currIdx,INT_MIN,INT_MAX);
    return currIdx==preorder.size();
}