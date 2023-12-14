class Solution {
public:
    vector<int> findPeaks(vector<int>& mountain) {
        vector<int> output;

        for (int i = 1; i < mountain.size()-1; i++)
        {
            if (mountain[i-1] < mountain[i] && mountain[i] > mountain[i+1])
            {
                output.push_back(i);
            }
        }

        return output;
    }
};