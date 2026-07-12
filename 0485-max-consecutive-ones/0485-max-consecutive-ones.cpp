class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int maxans = 0;
        for (int i = 0 ; i< nums.size() ; i++){
            if (nums[i] == 1){
                count++;
            }
            else{
                maxans = max(maxans, count);
                count = 0;
            }
            if (i+1 == nums.size()){
                maxans = max(maxans , count);
            }
        }
        return maxans;
    }
};