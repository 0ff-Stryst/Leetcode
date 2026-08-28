class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int a = 0;
        int b = m-1;
        while( a < n && b >= 0){
            if ( matrix[a][b] == target){
                return true;
            }
            else if(target < matrix[a][b]){
                b--;
            }
            else{
                a++;
            }
        }
        return false;
    }
};