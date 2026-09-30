class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {\
        if (k <= 1) return 0;
        
        int c = 0 ; 
        int j = 0 ;
        int pro = 1;
        for ( int i = 0 ; i < nums.size() ; i++){
            pro = pro * nums[i];
            while( pro >= k ){
                pro = pro / nums[j];
                j++;
            }
            c = c + i - j + 1;
        }
        return c ;
    }
};