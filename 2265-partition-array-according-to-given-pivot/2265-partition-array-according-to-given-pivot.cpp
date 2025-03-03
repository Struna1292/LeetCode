class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        
        vector<int> smaller;
        vector<int> equal;
        vector<int> larger;

        for (int n : nums)
        {
            if (n < pivot)
            {
                smaller.push_back(n);
            }
            else if (n == pivot)
            {
                equal.push_back(n);
            }
            else
            {
                larger.push_back(n);
            }
        }

        vector<int> output;

        for (int n : smaller)
        {
            output.push_back(n);
        }

        for (int n : equal)
        {
            output.push_back(n);
        }

        for (int n : larger)
        {
            output.push_back(n);
        }

        return output;
    }
};