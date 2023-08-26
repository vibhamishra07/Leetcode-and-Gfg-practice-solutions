class Solution {
public:
    int maxDepth(string s) {
        int n=s.length();
        stack<char>st;
        int maxDepth=0;
        for(int i=0; i<n; i++){
            if(s[i]=='(')st.push(s[i]);
            else if(s[i]==')'){
                if(st.size()>maxDepth) maxDepth=st.size();
                st.pop();
            }
        }
        return maxDepth;
    }
};