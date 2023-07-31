class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int maxProfit=0, j=0;
        for(int i=1; i<n; i++){
            if(prices[i]<prices[j]){
                j=i;
            }else{
               maxProfit= max(maxProfit, prices[i]-prices[j]);
            }
        }
        return maxProfit;
    }
};