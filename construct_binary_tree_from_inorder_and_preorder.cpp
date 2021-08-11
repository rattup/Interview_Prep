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
    int get(vector<int>& inorder,int start,int end,int val)
    {
        for(int i=start;i<=end;i++)
        if(inorder[i]==val)
        return i;
        return -1;
    }
    TreeNode* solve(vector<int>& preorder,vector<int>& inorder,int start,int end,int& ind)
    {
        if(start>end)
        return NULL;
        int val=preorder[ind];
        ind++;
        TreeNode* root=new TreeNode(val);
        int index=get(inorder,start,end,val);
        root->left=solve(preorder,inorder,start,index-1,ind);
        root->right=solve(preorder,inorder,index+1,end,ind);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int ind=0;
        return solve(preorder,inorder,0,preorder.size()-1,ind);
    
        
    }
};
