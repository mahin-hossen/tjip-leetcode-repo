/*
TC: 0(N)  //where N is equal to k
MC: 0(1)
*/

int inorderTraverse(TreeNode* root,int &k)
{
    if(!root) return -1; 
    
    int L = inorderTraverse(root->left,k);        
    k--;        
    if(k==0) return root->val;        
    int R = inorderTraverse(root->right,k);
    return max(L,R);
}
int kthSmallest(TreeNode* root, int k) 
{
    return inorderTraverse(root,k);
}