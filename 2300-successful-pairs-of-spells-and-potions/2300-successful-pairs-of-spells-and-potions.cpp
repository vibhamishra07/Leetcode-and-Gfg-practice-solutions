class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int>ans;
        sort(potions.begin(), potions.end());
        
        for(int i=0; i<spells.size(); i++){
            int count=0;
            int end=potions.size()-1;
            int start=0;
            while(start<=end){
                int mid=start+(end-start)/2;
                if((long long)spells[i]*(long long)potions[mid]>=success) end=mid-1;
                else{
                    start=mid+1;
                }
            }
             ans.push_back(potions.size()-start);
        }
        return ans;
    }
};