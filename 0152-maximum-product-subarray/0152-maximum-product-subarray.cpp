class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int mult=1;
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            mult*=nums[i];
            maxi=max(mult, maxi);
            if(mult==0){
                mult=1;
            }
        }
        mult=1;
        for(int i=n-1;i>=0;i--){
            mult*=nums[i];
            maxi=max(mult, maxi);
            if(mult==0){
                mult=1;
            }
        }
        return maxi;
    }
};