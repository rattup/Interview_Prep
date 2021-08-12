int dfs(int node,int parent,vector<int> adj[],int& cnt)
{
    int c=0;
    for(auto child:adj[node])
    {
        if(child!=parent)
        {
        int temp=dfs(child,node,adj,cnt);
        if(temp%2==0)
        cnt++;
        else
        c+=temp;
        }
    }
    return 1+c;
}
int Solution::solve(int A, vector<vector<int> > &B) {
    vector<int> adj[A+1];
    for(int i=0;i<B.size();i++)
    {
    adj[B[i][0]].push_back(B[i][1]);
    adj[B[i][1]].push_back(B[i][0]);
    }
    int cnt=0;
    dfs(1,-1,adj,cnt);
    return cnt;
}

