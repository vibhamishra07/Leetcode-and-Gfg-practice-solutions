class Solution {
public:
    
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n=piles.size();
        vector<vector<int>>dp(n+1, vector<int>(k+1, -1));
        return solve(piles, 0, k, n, dp);
    }
    int solve(vector<vector<int>>&piles, int i, int k, int n,vector<vector<int>>&dp){
        if(i>=n) return 0;
        
        if(dp[i][k]!=-1) return dp[i][k];
        
        int notTaken=solve(piles, i+1, k, n, dp);
        int taken=0;
        int sum=0;
        
        for(int j=0; j<min((int)piles[i].size(), k); j++){
            sum+=piles[i][j];
            
            taken=max(taken, sum+solve(piles, i+1, k-(j+1), n, dp));
        }
        
        return dp[i][k]=max(taken, notTaken);
    }
};