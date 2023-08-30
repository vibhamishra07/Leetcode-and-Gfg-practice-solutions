class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>>ans;
        ans.push_back(intervals[0]);
        int j=0;
        for(int i=1; i<intervals.size(); i++){
            if(intervals[i][0]<=ans[j][1]){
                if(intervals[i][1]<=ans[j][1]) continue;
                else ans[j]={ans[j][0], intervals[i][1]};
            }else{
                ans.push_back(intervals[i]);
                j++;
            }
        }
        return ans;
    }
};