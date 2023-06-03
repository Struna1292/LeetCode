class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {

        int m = l.size();
        vector<bool> output;
        output.reserve(m);

        for (int i = 0; i < m; i++)
        {
            vector<int> curr;
            for (int j = l[i]; j <= r[i]; j++)
            {
                curr.push_back(nums[j]);
            }

            sort(begin(curr), end(curr), greater<int>());

            if (curr.size() <= 2)
            {
                output.emplace_back(true);
                continue;
            }

            int diff = curr[1] - curr[0];
            int counter = 2;
            for (int j = 2; j < curr.size(); j++)
            {
                if (curr[j] - curr[j-1] == diff)
                {
                    counter++;
                }
                else
                {
                    break;
                }
            }
            
            if (counter == curr.size())
            {
                output.emplace_back(true);
            }
            else
            {
                output.emplace_back(false);
            }
        }

        return output;
    }
};