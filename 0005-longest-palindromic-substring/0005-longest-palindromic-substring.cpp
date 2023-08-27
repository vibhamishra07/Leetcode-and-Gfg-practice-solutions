class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        int maxLength=0, startIndex=0;
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(isPallindrome(s, i, j)){
                   if(j-i+1 > maxLength){
                        maxLength = j-i+1;
                        startIndex = i;
                    }
                }
                
            }
        }
        return s.substr(startIndex, maxLength);
    }
    
    bool isPallindrome(string &strPal,int i,int j){
        while(i<j){
            if(strPal[i]!=strPal[j]){
               return false;
            }
            j--;
            i++;
        }
        return true;
    }
};