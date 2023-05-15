class Solution {
public:
    int maxArea(vector<int>& height) {

        int output = 0;
        
        int i = 0;
        int j = height.size()-1;

        while (i < j)
        {
            int curr = 0;
            if (height[i] > height[j])
            {
                curr = height[j] * (j-i);
                j--;
            }
            else
            {
                curr = height[i] * (j-i);
                i++;
            }
            if (curr > output)
            {
                output = curr;
            }
        }

        return output;
    }
};