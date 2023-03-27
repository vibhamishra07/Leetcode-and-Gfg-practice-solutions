class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m+1, vector<int>(n+1, -1));
        
        return minPath(grid, dp, m-1, n-1);
    }
    int minPath(vector<vector<int>>& grid, vector<vector<int>>&dp, int m,int n){
        if(m==0 && n==0) return grid[m][n];
        if(m<0 || n<0) return 1e9;
        
        if(dp[m][n]!=-1) return dp[m][n];
        
        int up=minPath(grid, dp, m-1, n);
        int left=minPath(grid, dp, m, n-1);
        
        return dp[m][n]=grid[m][n]+min(up, left);
    }
};

