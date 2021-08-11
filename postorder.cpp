vector <int> postOrder(Node* root)
{
  Node* cur=root;
  vector<int> res;
  stack<Node*> st;
  while(cur || !st.empty())
  {
      while(cur)
      {
     st.push(cur);
     cur=cur->left;
      }
      Node* temp=st.top();
      if(temp->right)
      cur=temp->right;
      else
      {
          res.push_back(temp->data);
          st.pop();
          while(!st.empty() && (st.top())->right==temp)
          {
              temp=st.top();
              st.pop();
              res.push_back(temp->data);
          }
      }
      
  }
  return res;
}
