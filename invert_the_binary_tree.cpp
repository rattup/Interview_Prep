/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 void help(TreeNode* root)
 {
    TreeNode* temp=root->right;
    root->right=root->left;
    root->left=temp;
    if(root->left)
    help(root->left);
    if(root->right)
    help(root->right);

 }
TreeNode* Solution::invertTree(TreeNode* root) {
    if(!root)
    return nullptr;
    help(root);
    return root;
   

}

