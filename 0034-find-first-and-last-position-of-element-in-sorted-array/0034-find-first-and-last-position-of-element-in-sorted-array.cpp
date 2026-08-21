class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int leftindex = helper(nums , target , true);
        if(leftindex == -1){
            return {-1,-1};
        }

        int rightindex = helper(nums,target,false);
            return {leftindex, rightindex};
    }
        
        
private:
    int helper(vector<int>& nums , int target , bool f){
        int s = 0 ;
        int e = nums.size()-1;
        int index = -1;

        while(s<=e){
            int mid = s +(e-s)/2;
            
            if(nums[mid] == target){
                index = mid;
                if(f){
                    e = mid-1;
                }
                else{
                    s = mid+1;
                }
            }
            else if( nums[mid] > target){
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        return index;
    }
    
};