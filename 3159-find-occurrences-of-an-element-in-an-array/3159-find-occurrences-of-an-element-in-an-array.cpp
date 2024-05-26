class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        
        vector<int> ones;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == x)
            {   
                ones.push_back(i);
            }
        }


        vector<int> output(queries.size(), -1);

        for (int i = 0; i < queries.size(); i++)
        {
            if (queries[i] <= ones.size())
            {
                output[i] = ones[queries[i]-1];
            }
        }

        return output;
    }
};