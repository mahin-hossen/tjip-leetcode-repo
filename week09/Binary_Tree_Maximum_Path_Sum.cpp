/*
TC : 0(N)   //here N is number of nodes of tree
MC : 0(H)   //here H Depth of the tree
*/
int pathSum;
int maxChainSum(TreeNode* root)
{
    if(root==NULL) return 0;
    int L = maxChainSum(root->left);
    int R = maxChainSum(root->right);
    pathSum = max(L+R+root->val,pathSum);
    return max(0,max(L,R)+root->val);
}
int maxPathSum(TreeNode* root)
{        
    pathSum = INT_MIN;
    int chainSum = maxChainSum(root);
    return pathSum;
}