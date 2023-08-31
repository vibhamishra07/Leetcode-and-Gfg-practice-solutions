class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        long long nSum=n*(n+1)/2;
        long long sum=0;
        for(int i=0; i<n; i++){
            sum+=nums[i];
        }
        return nSum-sum;
    }
};