class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int indegree[numCourses];
        for(int i=0;i<numCourses;i++)
        indegree[i]=0;
        vector<int> adj[numCourses];
        queue<int> q;
        for(auto it:prerequisites)
        {
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
            
            
        }
        for(int i=0;i<numCourses;i++)
            if(indegree[i]==0)
                q.push(i);
        int cnt=0;
        while(!q.empty())
        {
            int temp=q.front();
            q.pop();
            cnt++;
            for(auto it:adj[temp])
            {
                indegree[it]--;
                if(indegree[it]==0)
                q.push(it);
                
            }

            
        }
        if(cnt==numCourses)
            return true;
        return false;
        
        
    }
};
