class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long maxsum = 0;
        long long cursum = 0;
        unordered_map<int,int> m;
        for ( int i = 0 ; i < k ; i++){
            cursum = cursum + nums[i];
            m[nums[i]]++;
        }
        if(m.size() == k){
            maxsum = max(maxsum , cursum);
        }  
        for(int i = k ; i<nums.size() ; i++){
            cursum = cursum + nums[i];
            m[nums[i]]++;
            cursum = cursum - nums[i-k];
            m[nums[i-k]]--;

            if(m[nums[i-k]] == 0){
                m.erase(nums[i-k]);
            }
            if(m.size() == k){
                maxsum = max(maxsum , cursum);
            }
        }
        return maxsum;
    }
};