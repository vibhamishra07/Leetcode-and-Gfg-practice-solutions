class Solution {
public:
    bool isAnagram(string s, string t) {
        int n=s.length();
        int m=t.length();
        if(n!=m) return false;
        int arr[27]={0};
        for(int i=0; i<n; i++){
            arr[s[i]-97]++;
        }
        for(int i=0; i<n; i++){
            if(arr[t[i]-97]<1) return false;
            arr[t[i]-97]--;
        }
        return true;
    }
};