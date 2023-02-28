class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer,Integer> h=new HashMap<>();
        int n=nums.length;
        int[] arr=new int[2];
        for(int i=0; i<n; i++){
            h.put(nums[i], i);
        }
        for(int i=0; i<n; i++){
            int left=target-nums[i];
            if(h.containsKey(left) && h.get(left)!=i){
                arr[0]=i;
                arr[1]=h.get(left);
                return arr;
            }
        }
        return arr;
    }
}