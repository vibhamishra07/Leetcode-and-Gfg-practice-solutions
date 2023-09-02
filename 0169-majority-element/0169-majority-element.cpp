class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=nums.size()/2;
        unordered_map<int, int>mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        for(auto m:mp){
            
            if(m.second>count) return m.first;
        }
        return 1;
    }
};