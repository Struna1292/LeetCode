class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> output;
        if (nums.size() == 0)
        {
            return output;
        }
        else if (nums.size() == 1)
        {
            output.push_back(to_string(nums[0]));
            return output;
        }
        sort(begin(nums), end(nums));
        nums.push_back(0);
        string curr;
        string empty;
        int start = nums[0];
        int before = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] - 1 != before)
            {
                if (start == before)
                {
                    output.push_back(to_string(before));
                    start = nums[i];
                }
                else
                {
                    string startStr = to_string(start);
                    for (int j = 0; j < startStr.length(); j++)
                    {
                        curr.push_back(startStr[j]);
                    }
                    curr.push_back('-');
                    curr.push_back('>');
                    string beforeStr = to_string(before);
                    for (int j = 0; j < beforeStr.length(); j++)
                    {
                        curr.push_back(beforeStr[j]);
                    }
                    output.push_back(curr);
                    curr = empty;
                    start = nums[i];
                }
            }
            before = nums[i];
        }
        return output;
    }
};