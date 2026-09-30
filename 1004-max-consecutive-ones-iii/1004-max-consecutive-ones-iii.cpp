class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int start = 0 ;
        int maxones = 0 ;
        int zerocount = 0;

        for ( int i =0 ; i < nums.size() ; i++){
            if ( nums[i] == 0){
                zerocount++;
            }

            while( zerocount > k){
                if(nums[start] == 0){
                    zerocount--;
                }
                start++;
            }
            maxones = max(maxones , i-start+1);
        }
        return maxones;
    }
};