class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int i = 0;
        int j = height.size()-1;

        int output = 0;

        while (i < j) {
            int currHeight = min(height[i], height[j]);

            if (output < currHeight * (j - i)) {
                output = currHeight * (j - i);
            }

            if (height[i] < height[j]) {
                i++;
            }
            else {
                j--;
            }
        }

        return output;
    }
};