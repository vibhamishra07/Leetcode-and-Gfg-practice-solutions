class Solution {
public:
    long long MOD = 1000000007;
    bool findApple(vector<string>& pizza, int startRow, int endRow, int startCol, int endCol) {
        for (int i = startRow; i <= endRow; i++) {
            for (int j = startCol; j <= endCol; j++) {
                if (pizza[i][j] == 'A') 
                    return true;
            }
        }
        return false;
    }
    int ways(vector<string>& pizza, int k) {
        int rows = pizza.size(), numCols = pizza[0].size();
        vector<vector<vector<int>>> dp(rows, vector<vector<int>>(numCols, vector<int>(k, -1)));
        int ans = findWays(pizza, dp, 0, 0, k - 1);
        return ans; 
    }
    
    
    int findWays(vector<string>& pizza, vector<vector<vector<int>>>& dp, int startRow, int startCol, int cutsLeft){
       int rows = pizza.size();
        int numCols = pizza[0].size();
        
        if (cutsLeft == 0) 
            return 1;
        if (dp[startRow][startCol][cutsLeft] != -1) 
            return dp[startRow][startCol][cutsLeft];
        long long ans = 0;
            
        for (int row = startRow; row < rows - 1; row++) {
            bool upperPartApple = findApple(pizza, startRow, row, startCol, numCols - 1);
            bool lowerPartApple = findApple(pizza, row + 1, rows - 1, startCol, numCols - 1);

            if (upperPartApple && lowerPartApple) {
                int nextWays = findWays(pizza, dp, row + 1, startCol, cutsLeft - 1);
                ans = (ans + nextWays) % MOD;
            }
        }
        for (int col = startCol; col < numCols - 1; col++) {
            bool lefPartApple = findApple(pizza, startRow, rows - 1, startCol, col); 
            bool rightPartApple = findApple(pizza, startRow, rows - 1, col + 1, numCols - 1);

            if (lefPartApple && rightPartApple) {
                int nextWays = findWays(pizza, dp, startRow, col + 1, cutsLeft - 1);
                ans = (ans + nextWays) % MOD;
            }
        }
        return dp[startRow][startCol][cutsLeft] = (int)ans;
    }
};