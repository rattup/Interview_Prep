class Solution {
    public:
    void print_left(Node* root,vector<int>& res)
    {
        if(!root)
        return;
        if(root->left)
        {
            res.push_back(root->data);
            print_left(root->left,res);
        }
        else if(root->right)
        {
            res.push_back(root->data);
            print_left(root->right,res);
        }
        
    }
    void print_right(Node* root,vector<int>& res)
    {
        if(!root)
        return;
        if(root->right)
        {
           
            print_right(root->right,res);
            res.push_back(root->data);
        }
        else if(root->left)
        {
           
            print_right(root->left,res);
            res.push_back(root->data);
        }
        
    }
    void print_leaf(Node* root,vector<int>& res)
    {
        if(!root)
        return;
        print_leaf(root->left,res);
        if(!root->left && !root->right)
        res.push_back(root->data);
        print_leaf(root->right,res);
    }

    vector <int> printBoundary(Node *root)
    {
        vector<int> res;
        res.push_back(root->data);
        print_left(root->left,res);
        print_leaf(root,res);
        print_right(root->right,res);
        return res;
    
    }
};
