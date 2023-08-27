class Solution {
public:
    int beautySum(string s) {
        int n=s.length();
        int res=0;
        for(int i=0; i<n; i++){
            int mp[26]={0};
            for(int j=i; j<n; j++){
                mp[s[j]-'a']++;
                res=res+beauty(mp);
            }
        }
        return res;
    }
    int beauty(int mp[]){
        int mf=-1;
        int minf=1e9;
        
        for(int i=0; i<26; i++){
            mf=max(mf, mp[i]);
            if(mp[i]>=1){
                minf=min(minf, mp[i]);
            }
        }
        return mf-minf;
    }
};