class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long count=0, total=0;
        int len=nums.size();
        
        for(int i=0; i<len;i++){
            if(nums[i]==0){
                count++;
                total+=count;
            }else{
                count=0;
            }
        }
        return total;
    }
};