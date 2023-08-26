class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length()==1) return true;
        unordered_map<char,  char>fmp;
        unordered_map<char,  bool>smp;
    
        for(int i=0; i<s.length(); i++){
            if(((!smp[t[i]]) && ((fmp[s[i]] && fmp[s[i]]==t[i]) || !(fmp[s[i]]))) || (smp[t[i]] && fmp[s[i]]==t[i])){
                smp[t[i]]=true;
                fmp[s[i]]=t[i];
            }else{
                return false;
            }
        }
        return true;
    }
};