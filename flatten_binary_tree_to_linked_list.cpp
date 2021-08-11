/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 TreeNode* predecessor(TreeNode* root)
 {
     while(root->right)
     root=root->right;
     return root;
 }
TreeNode* Solution::flatten(TreeNode* root) {
    TreeNode* cur=root;
    while(cur)  // Morris tree traversal technique
    {
        if(cur->left)
        {
            TreeNode* pre=predecessor(cur->left); 
            pre->right=cur->right;
            cur->right=cur->left;
            cur->left=nullptr;
            cur=cur->right;

        }
        else
        cur=cur->right;
    }
   return root;
}

