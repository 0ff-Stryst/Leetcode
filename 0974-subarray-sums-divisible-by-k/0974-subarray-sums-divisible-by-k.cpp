class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        int sum = 0 ;
        int count = 0 ;
        map[0] = 1;
        for ( int i = 0 ; i< nums.size() ; i++){
            sum = sum + nums[i];
            int rem = sum % k;
            if (rem < 0 ){
                rem = rem + k;
            }
            if ( map.find(rem) != map.end()){
                count = count+ map[rem];
            }
            map[rem]++;
        }
        return count;
    }
};