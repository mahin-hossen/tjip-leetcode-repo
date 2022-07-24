/*
TC : 0(V)  //number of nodes of the tree
MC : 0(D)   //maximum depth of the tree
*/
int maxDepth(TreeNode* root) 
{
    if(!root) return 0;
    int left = maxDepth(root->left) + 1;
    int right = maxDepth(root->right) + 1;
    
    return max(left,right);
}