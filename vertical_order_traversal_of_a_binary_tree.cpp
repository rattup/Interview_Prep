/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* root) {
    vector<vector<int>> res;
    if(!root)
    return res;
    int mini,maxi;
    mini=0;
    maxi=0;
    unordered_map<int,vector<int> > mp;
    queue<pair<TreeNode*,int>> q;
    q.push({root,0});

    while(!q.empty())
    {
        auto p=q.front();
        q.pop();
        TreeNode* temp=p.first;
        int level=p.second;
        mp[level].push_back(temp->val);
        if(temp->left)
        {
        q.push({temp->left,level-1});
        mini=min(mini,level-1);
        maxi=max(maxi,level-1);
        }
        if(temp->right)
        {
        q.push({temp->right,level+1});
        mini=min(mini,level+1);
        maxi=max(maxi,level+1);
        }
    }
    for(int i=mini;i<=maxi;i++)
    res.push_back(mp[i]);
    return res;


}

