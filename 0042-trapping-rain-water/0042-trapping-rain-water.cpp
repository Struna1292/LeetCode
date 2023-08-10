class Solution {
public:
    int trap(vector<int>& height) {

        vector<int> maxLeft(height.size(), 0);
        vector<int> maxRight(height.size(), 0);

        int biggest = 0;
        for (int i = 0; i < height.size(); i++)
        {
            maxLeft[i] = biggest;
            if (height[i] > biggest)
                biggest = height[i];
        }

        biggest = 0;
        for (int i = height.size()-1; i >= 0; i--)
        {
            maxRight[i] = biggest;
            if (height[i] > biggest)
                biggest = height[i];
        }

        int output = 0;

        for (int i = 0; i < height.size(); i++)
        {
            if (height[i] < min(maxLeft[i], maxRight[i]))
                output += min(maxLeft[i], maxRight[i]) - height[i];
        }

        return output;
    }
};