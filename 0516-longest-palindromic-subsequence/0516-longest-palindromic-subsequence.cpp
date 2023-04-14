class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n=s.length();
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        string s2=s;
        reverse(s2.begin(), s2.end());
        return dpSolve(s,s2, n, n,dp);
        
        
    }
    
    int dpSolve(string &s,string &s2, int m, int n,vector<vector<int>>&dp){
        if(m==0 || n==0) return dp[m][n]=0;
        if(dp[m][n]!=-1) return dp[m][n];
        if(s[m-1]==s2[n-1]) return dp[m][n]=1+dpSolve(s,s2 ,m-1, n-1,dp);
        return dp[m][n]= max(dpSolve(s, s2, m, n-1, dp), dpSolve(s,s2, m-1, n, dp));
    }
};