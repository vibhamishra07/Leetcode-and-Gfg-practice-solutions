class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int e=0, count=0;
        for(int i=0; i<nums.size(); i++){
            if(count==0){
                count=1;
                e=nums[i];
            }else if(e==nums[i]){
                count++;
            }else count--;
        }
        return e;
    }
};