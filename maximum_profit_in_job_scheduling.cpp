class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n=startTime.size();
        vector<vector<int>> v(n);
        for(int i=0;i<n;i++)
        v[i]={endTime[i],startTime[i],profit[i]};
        sort(v.begin(),v.end());
        vector<int> dp(n);
        dp[0]=v[0][2];
        for(int i=1;i<n;i++)
        {
            int inc=v[i][2];
            int last=-1;
            int low=0,high=i-1;
            while(low<=high)
            {
                int mid=(low+high)>>1;
                if(v[mid][0]<=v[i][1])
                {
                    last=mid;
                    low=mid+1;
                }
                else
                high=mid-1;
            }
            if(last!=-1)
            inc+=dp[last];
            int winc=dp[i-1];
            dp[i]=max(inc,winc);
        }
        return dp[n-1];
        
    }
};
