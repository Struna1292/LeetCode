class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(begin(nums), end(nums));

        vector<int> output;

        for (int i = 0; i < queries.size(); i++)
        {
            int curr = 0;
            int counter = 0;
            for (int j = 0; j < nums.size(); j++)
            {
                curr += nums[j];
                if (curr <= queries[i])
                {
                    counter++;
                }
                else
                {
                    break;
                }
            }
            output.push_back(counter);
        }
        
        return output;
    }
};