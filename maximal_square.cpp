class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int row=matrix.size();
        if(row==0)
        return 0;
        int col=matrix[0].size();
        int dp[row+1][col+1];
        memset(dp,0,sizeof(dp));
        int largest=0;
        for(int i=1;i<=row;i++)
        {
            for(int j=1;j<=col;j++)
            {
                if(matrix[i-1][j-1]=='1')
                {
                dp[i][j]=1+min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]});
                largest=max(largest,dp[i][j]);
                }
            }
        }
        return largest*largest;
        
        
    }
};
