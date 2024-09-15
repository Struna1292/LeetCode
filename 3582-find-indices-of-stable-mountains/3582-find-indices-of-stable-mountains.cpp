class Solution {
public:
    vector<int> stableMountains(vector<int>& height, int threshold) {
        
        vector<int> output;

        for (int i = 1; i < height.size(); i++)
        {
            if (height[i-1] > threshold)
            {
                output.push_back(i);
            }
        }

        return output;
    }
};