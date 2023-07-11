class Solution {
public:
    vector<int> lexicalOrder(int n) {
        
        vector<string> nums(n, "");

        for (int i = 1; i <= n; i++)
        {
            nums[i-1] = to_string(i);
        }

        sort(begin(nums), end(nums));

        vector<int> output(n, 0);
        for (int i = 0; i < n; i++)
        {
            output[i] = stoi(nums[i]);
        }

        return output;
    }
};