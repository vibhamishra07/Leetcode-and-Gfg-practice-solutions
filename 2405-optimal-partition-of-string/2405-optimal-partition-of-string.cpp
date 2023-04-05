class Solution {
public:
    int partitionString(string s) {
        unordered_map<char, bool> mp;
        int i = 0, count = 0;
        while(i<s.length()) {
            if (mp.find(s[i]) != mp.end()) {
                count++; 
                mp.clear(); 
            }
            mp[s[i]] = true; 
            i++;
        }
        return count + 1;
    }
};