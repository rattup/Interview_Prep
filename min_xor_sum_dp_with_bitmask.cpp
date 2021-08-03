class Solution {
    int find(int i,int mask,int &n,vector<int>& nums1,vector<int>& nums2,vector<vector<int>>& dp)
    {
        if(i<0)
        return 0;
        if(dp[i][mask]!=-1)
        return dp[i][mask];
        int ans=INT_MAX;
        for(int j=0;j<n;j++)
        {
            if(mask & (1<<j))
            ans=min(ans,(nums1[i]^nums2[j])+find(i-1,mask^(1<<j),n,nums1,nums2,dp));
        }
        return dp[i][mask]=ans;
        
    }
public:
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int mask=(1<<n)-1;
        vector<vector<int>> dp(n,vector<int>(mask+1,-1));
        //int dp[n][mask+1];
       // memset(dp,-1,sizeof(dp));
        return find(n-1,mask,n,nums1,nums2,dp);
        
    }
};
