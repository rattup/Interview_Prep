class Solution
{
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2 )
    {
       if(!root)
       return nullptr;
       if(root->data == n1 || root->data==n2)
       return root;
       auto left=lca(root->left,n1,n2);
       auto right=lca(root->right,n1,n2);
       if(left && right)
       return root;
       else if(left)
       return left;
       else
       return right;
    }
};
