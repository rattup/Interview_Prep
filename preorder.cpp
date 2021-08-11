vector <int> preorder(Node* root)
{
  vector<int> res;
  Node* cur=root;
  stack<Node*> st;
  while(cur || !st.empty())
  {
      
      while(cur)
      {
          res.push_back(cur->data);
          st.push(cur);
          cur=cur->left;
      }
      
          Node* temp=st.top();
          st.pop();
          if(temp->right)
          cur=temp->right;
      
      
  }
  return res;
}
