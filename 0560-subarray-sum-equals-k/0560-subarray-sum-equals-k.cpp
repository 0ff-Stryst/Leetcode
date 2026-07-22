class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        int n = nums.size();
        int sum = 0;
        int count = 0 ;
        map[0] = 1;
        for ( int i = 0 ; i< n ; i++){
            sum = sum + nums[i];
            int target = sum - k;

            if ( map.find(target) != map.end()){
                count = count + map[target];
            }
            map[sum]++ ;
        }
        return count;
    }
};