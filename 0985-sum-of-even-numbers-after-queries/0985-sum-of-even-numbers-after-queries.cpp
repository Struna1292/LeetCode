class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        
        int evenSum = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] % 2 == 0)
            {
                evenSum += nums[i];
            }
        }

        vector<int> output;
        for (int i = 0; i < queries.size(); i++)
        {
            int before = nums[queries[i][1]];
            int val = queries[i][0];
            int after = before + val;

            if (before % 2 == 0)
            {
                if (after % 2 == 0)
                {
                    evenSum += val;
                }
                else
                {
                    evenSum -= before;
                }
            }
            else
            {
                if (after % 2 == 0)
                {
                    evenSum += after;
                }
            }
            nums[queries[i][1]] = after;
            output.push_back(evenSum);
        }

        return output;
    }
};