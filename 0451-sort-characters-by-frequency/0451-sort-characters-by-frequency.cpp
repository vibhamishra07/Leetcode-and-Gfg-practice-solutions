class Solution {
public:
    string frequencySort(string s) {
        int n=s.length();
        
        unordered_map<char, int>mp;
        for(int i=0; i<n; i++){
            mp[s[i]]++;
        }
        
        priority_queue< pair<char, int>, vector<pair<char,int>>, Lambda > pq;
        for(auto &m:mp){
            pq.push({m.first, m.second});
        }
        
        string ans="";
        while(!pq.empty()){
            pair<char,int> p=pq.top();
            pq.pop();
            while(p.second!=0){
                ans+=p.first;
                p.second--;
            }
        }
        return ans;
    }
    
    class Lambda{
        public:
        bool operator()(pair<char, int> p1, pair<char,int> p2){
            return p1.second<p2.second;
        }
    };
};