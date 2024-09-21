class Solution {
public:
    vector<int> lexicalOrder(int n) {
        
        vector<string> nums;

        for (int i = 1; i <= n; i++)
        {   
            nums.push_back(to_string(i));
        }   

        sort(begin(nums), end(nums));

        vector<int> output;

        for (string s : nums)
        {
            output.push_back(stoi(s));
        }

        return output;
    }
};