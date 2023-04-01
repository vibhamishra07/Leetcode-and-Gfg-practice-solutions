class Solution {
public:
    int search(vector<int>& nums, int target) {
        int e=nums.size()-1;
        int s=0;
        while(s<=e){
            int mid=(s+e)/2;
            if(nums[mid]==target) return mid;
            if(nums[mid]>target) e=mid-1;
            else s=mid+1;
        }
        return -1;
    }
};