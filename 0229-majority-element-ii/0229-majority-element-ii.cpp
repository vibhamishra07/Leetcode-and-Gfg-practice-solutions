class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int e1=INT_MIN, e2=INT_MIN, c1=0, c2=0;
        int majorityCount=(int)(nums.size()/3) + 1;
        for(int i=0; i<nums.size(); i++){
            if(c1==0 && nums[i]!=e2){
                c1=1;
                e1=nums[i];
            }else if(c2==0 && nums[i]!=e1){
                c2=1;
                e2=nums[i];
            }else if(nums[i]==e1){
                c1++;
            }else if(nums[i]==e2){
                c2++;
            }else{
                c1--, c2--;
            }
        }
        c1=0, c2=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==e1) c1++;
            else if(nums[i]==e2) c2++;
        }
        vector<int>ans;
        
        if(c1>=majorityCount) ans.push_back(e1);
        if(c2>=majorityCount) ans.push_back(e2);
        return ans;
    }
};