class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        sort(begin(nums), end(nums));

        int counter = 1;
        int prev = nums[0];

        vector<int> answer;

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] != prev)
            {
                if (counter == 1)
                {
                    answer.push_back(prev);
                }
                prev = nums[i];
                counter = 1;
            }
            else
            {
                counter++;
            }
        }
        if (counter == 1)
        {
            answer.push_back(prev);
        }

        return answer;
    }
};