/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int sum=0;
    void find(TreeNode* root,bool flag)
    {
        if(!(root->left) && !(root->right) && flag)
        {
            sum+=root->val;
            return;
        }
        if(root->left)
        find(root->left,true);
        if(root->right)
        find(root->right,false);
        
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root)
        return 0;
        find(root,false);
        return sum;
            
        
        
    }
};
