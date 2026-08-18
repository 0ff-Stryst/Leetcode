class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n  = nums.size();
        k = k % n;
        helper(nums, 0 , n-1);
        helper(nums, 0 , k-1);
        helper(nums , k , n-1);
        
    }

    void helper(vector<int> &num, int start , int end){
        while( start  <= end){
            int temp = num[start];
            num[start] = num[end];
            num[end] = temp;
            start++;
            end--;
        }
    }
};