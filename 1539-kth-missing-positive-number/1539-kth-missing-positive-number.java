class Solution {
    public int findKthPositive(int[] arr, int k) {
        int n=arr.length;
        int j=1, count=1;
        for(int i=0; i<n; i++){
            while(j<arr[i] && count<k){
                if(count==k) return j;
                j++;
                count++;
            }
            if(count==k && j!=arr[i]) return j;
            j=arr[i]+1;
           
        }
        
        while(count<k){
            j++;
            count++;
        }
        return j ;
        
    }
}