class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxC=0, count=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==0){
                maxC=max(maxC, count);
                count=0;
                continue;
            }
            count++;
        }
        return max(maxC, count);
    }
};