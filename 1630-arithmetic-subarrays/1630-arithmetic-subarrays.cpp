class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        
        vector<bool> output;

        for (int i = 0; i < l.size(); i++)
        {
            vector<int> curr(r[i]+1-l[i], 0);
            int j = l[i];
            for (int i = 0; i < curr.size(); i++)
            {
                curr[i] = nums[j];
                j++;
            }

            sort(begin(curr), end(curr));

            int diff = curr[1] - curr[0];

            bool match = true;
            for (int i = 1; i < curr.size()-1; i++)
            {
                if (curr[i+1] - curr[i] != diff)
                {
                    match = false;
                    break;
                }
            }

            output.push_back(match);
        }   

        return output;
    }
};