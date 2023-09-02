class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int sum=0, count=0;
        unordered_map<int, int>prefixSum{0};
        for(int i=0; i<n; i++){
           sum+=nums[i];
           if(sum==k)count++;
           if(prefixSum[sum-k]){
               count+=prefixSum[sum-k];
           }
           prefixSum[sum]++;
        }
        return count;
    }
    
};