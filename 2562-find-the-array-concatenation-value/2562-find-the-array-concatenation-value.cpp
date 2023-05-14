class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        
        long long output = 0;

        int i = 0;
        int j = nums.size()-1;
        while (i < j)
        {
            string s1 = to_string(nums[i]);
            string s2 = to_string(nums[j]);
            output += stoi(s1 + s2);
            i++;
            j--;
        }

        if (nums.size() % 2 != 0)
        {
            output += nums[i];
        }

        return output;
    }
};