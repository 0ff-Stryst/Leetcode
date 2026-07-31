class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int n = nums.size();
        long long cursum = 0 ;
        long long maxsum = 0 ;
        
        for ( int i = 0 ; i < k ; i++){
            cursum = cursum + nums[i];
            m[nums[i]]++;
        }

        if( m.size() == k){
            maxsum = cursum;
        }

        for( int j = k ; j < n ; j++){
            cursum = cursum + nums[j];
            m[nums[j]]++;

            cursum = cursum - nums[j-k];
            m[nums[j-k]]--;

            if (m[nums[j-k]] == 0){
                m.erase(nums[j-k]);
            }
            if ( m.size() == k){
                maxsum = max(maxsum , cursum);
            }
        }
        return maxsum;
    }
};