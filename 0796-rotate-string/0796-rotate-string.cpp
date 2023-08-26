class Solution {
public:
    bool rotateString(string s, string goal) {
        int n=goal.length(), m=s.length();
        if(n!=m) return false;
        string res=s+ s;

        for(int i=0; i<=n; i++){
            if(res.substr(i, n)==goal) return true;
        }
        return false;
    }
};