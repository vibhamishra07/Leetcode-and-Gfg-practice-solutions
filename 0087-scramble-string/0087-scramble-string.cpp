class Solution {
public:
    unordered_map<string, bool>mp;
     bool sol(string s1, string s2){
        if(s1==s2) return true;
        
        if(s1.length() != s2.length()) return false;
        
        string key= s1+"_"+s2;
        if(mp.find(key)!=mp.end()) return mp[key];
        
        int n=s1.length();
        bool result=false;
        for(int i=1; i<n; i++){
            
            bool not_swapped=sol(s1.substr(0, i), s2.substr(0, i)) && sol(s1.substr(i, n-i), s2.substr(i, n-i));
            if(not_swapped) {result=true; break;}
            
            bool swapped=sol(s1.substr(0, i), s2.substr(n-i, i)) && sol(s1.substr(i, n-i), s2.substr(0,n-i));
             if(swapped)  {result=true; break;}
        }
        return mp[key]=result;
    }
    
    bool isScramble(string s1, string s2) {
        
        return sol(s1, s2);
    }
    
   
};