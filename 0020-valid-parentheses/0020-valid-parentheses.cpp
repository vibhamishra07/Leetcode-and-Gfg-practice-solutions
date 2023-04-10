class Solution {
public:
    bool isValid(string s) {
        int n=s.length();
        if(n<=1) return false;
        stack<char> st;
        st.push(s[0]);
        for(int i=1; i<n; i++){
           if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
               st.push(s[i]);
           }else{
               if(st.size()==0) return false;
               char k=st.top();
               if((k=='(' && s[i]==')') || (k=='[' && s[i]==']') || (k=='{' && s[i]=='}')){
                   st.pop();
               }else return false;
           }
        }
        if(st.size()==0) return true;
        else return false;
    }
};