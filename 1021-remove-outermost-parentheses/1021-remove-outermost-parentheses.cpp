class Solution {
public:
    string removeOuterParentheses(string s) {
        int count=0;
        string ans="";
        
        for(int i=0; i<s.length(); i++){
            if(s[i]=='(' && count++>0){
                ans+='(';
            }
            if(s[i]==')' && count-->1){
                ans+=')';
            }
        }
        return ans;
    }
};