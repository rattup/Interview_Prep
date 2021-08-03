class Solution {
    int find(int left,int right,vector<int>& nums,vector<vector<int>>& dp)
    {
        if(left>right)
        return 0;
        if(dp[left][right]!=-1)
        return dp[left][right];
        int ans=INT_MIN;
        for(int i=left;i<=right;i++)
        {
            int a=left-1<0?1:nums[left-1];
            int b=right+1>=nums.size()?1:nums[right+1];
            ans=max(ans,a*b*nums[i]+find(left,i-1,nums,dp)+find(i+1,right,nums,dp));
        }
        return dp[left][right]=ans;
    }
public:
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        int left=0;
        int right=n-1;
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return find(left,right,nums,dp);
        
        
        
    }
};
