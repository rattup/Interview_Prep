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
public:
    TreeNode* predecessor(TreeNode* root,TreeNode* cur)
    {
        while(root->right && root->right!=cur)
        root=root->right;
        return root;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode* cur;
        cur=root;
        while(cur)
        {
            if(!cur->left)
            {
                res.push_back(cur->val);
                cur=cur->right;
            }
            else
            {
                TreeNode* pre=predecessor(cur->left,cur);
                if(!pre->right)
                {
                    pre->right=cur;
                    cur=cur->left;
                }
                else
                {
                    pre->right=nullptr;
                    res.push_back(cur->val);
                    cur=cur->right;
                }
            }
        }
        return res;
        
    }
};
