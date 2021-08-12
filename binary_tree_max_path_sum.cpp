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
    int solve(TreeNode* root,int& maxi)
    {
        if(!root)
        return 0;
        int left=solve(root->left,maxi);
        int right=solve(root->right,maxi);
        int sum1=root->val+left+right;
        int sum2=root->val+max({left,right,0});
        maxi=max({sum1,sum2,maxi});
        return sum2;
        
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        solve(root,maxi);
        return maxi;
        
    }
};
