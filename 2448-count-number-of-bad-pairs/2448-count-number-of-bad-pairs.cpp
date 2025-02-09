class Solution {
public:
    long long countBadPairs(vector<int>& nums) {

        long long output = 0;

        for (int i = nums.size()-1; i > 0; i--)
        {
            output += i;
        }

        cout << "total: " <<  output << endl;

        map<int, int> mp;

        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]-i]++;
        }

        for (auto itr = mp.begin(); itr != mp.end(); itr++)
        {
            if (itr->second > 1)
            {
                for (int i = itr->second-1; i > 0; i--)
                {
                    output -= i;
                }
            }
        }

        return output;
    }
};