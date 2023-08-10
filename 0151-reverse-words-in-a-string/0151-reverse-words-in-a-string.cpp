class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string words="";
        for(int i=0; i<s.length(); i++){
            if(s[i]!=' '){
                words+=s[i];
            }else if(words!=""){
                st.push(words);
                words="";
            }
        }
        if(words!="") st.push(words);
        words="";
        while(st.size()!=1){
            words+=st.top()+" ";
            st.pop();
        }
        words+=st.top();
        st.pop();
        return words;
    }
};