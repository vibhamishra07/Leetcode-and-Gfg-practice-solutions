class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int count=0;
        int end=INT_MIN;
        for(int i=0; i<intervals.size(); i++){
            if(intervals[i][0]>=end) {
                end=intervals[i][1];
            }
            else count++;
        }
        return count;
    }
    
    bool static cmp(vector<int>&a, vector<int> &b){
        return a[1]<b[1];
    }
};