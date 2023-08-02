class Solution {
public:
    int climbStairs(int n) {
        // vector<int>dp(n+1, -1);
        // return helper(n, dp);
        return helper2(n);

    }
//     int helper(int n, vector<int>&dp){ //time limit exceeded
//         if(n<0) return 0;
//         if(n==0) return 1;
//         if(dp[n]!=-1) return dp[n];
//         int one=climbStairs(n-1);
//         int two=climbStairs(n-2);
//         return dp[n]=one+two;
        
//     }
    
    int helper2(int n){ 
        if(n==1) return 1;
        if(n==2) return 2;
        int pr=1, cur=2;
        for(int i=3; i<=n; i++){
            int sum=pr+cur;
            pr=cur;
            cur=sum;
        }
        return cur;
    }
    
};