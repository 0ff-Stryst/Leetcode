class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int length = 0;
        int width = n - 1;
        int area = 0;

        while (length < width) {
            int l = width - length;
            int w = min(height[length] , height[width]);
            int pro = l * w;
            area = max(area , pro);

            if(height[length] < height[width]){
                length++;
            }
            else{
                width--;
            }
        }
        return area;
    }
};