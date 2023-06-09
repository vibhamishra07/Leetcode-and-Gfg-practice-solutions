class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>ds;
        int freq[nums.size()+1];
        memset(freq, 0, sizeof(freq));
        helper(nums, ans, ds, freq);
        return ans;
    }
    void helper(vector<int>& nums, vector<vector<int>>& ans, vector<int>& ds, int* freq){
        if(ds.size()==nums.size()){
            ans.push_back(ds);
            return;
        }
        
        for(int i=0; i<nums.size(); i++){
            if(!freq[i]){
                ds.push_back(nums[i]);
                freq[i]=1;
                helper(nums, ans, ds, freq);
                freq[i]=0;
                ds.pop_back();
            }
        }
    }
};