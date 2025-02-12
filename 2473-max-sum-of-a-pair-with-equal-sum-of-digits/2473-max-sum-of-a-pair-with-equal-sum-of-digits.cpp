class Solution {
public:
    int maximumSum(vector<int>& nums) {
        map<int, multiset<int>> mp; // key represents sum of digits, and value represents every number for this sum

        for (int n : nums)
        {
            string s = to_string(n);
            int digitSum = 0;
            
            for (char c : s)
            {
                digitSum += c-'0';
            }

            mp[digitSum].insert(n);
        }

        int output = -1;

        for (auto itr = mp.begin(); itr != mp.end(); itr++)
        {
            if (itr->second.size() >= 2)
            {
                int curr = 0;
                int i = 0;
                for (auto itr2 = itr->second.rbegin(); itr2 != itr->second.rend(); itr2++)
                {
                    i++;
                    curr += *(itr2);
                    if (i == 2)
                    {
                        break;
                    }
                }

                if (curr > output)
                {
                    output = curr;
                }
            }
        }

        return output;
    }
};