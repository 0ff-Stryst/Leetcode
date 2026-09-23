class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n, 1);
        vector<int> right(n, 1);
        vector<int> ans(n);
       
       int leftpro = 1;
        for(int i = 1 ; i < n ;i++){
            leftpro = leftpro * nums[i-1];
            left[i] = leftpro;
        }
        int rightpro = 1;
        for(int i = n - 2 ; i >= 0 ; i--){
            rightpro = rightpro * nums[i+1];
            right[i] = rightpro;
        }

        for(int i = 0 ; i < n ; i++ ) {
            ans[i] = left[i] * right[i];
        }

        return ans;


    }
};