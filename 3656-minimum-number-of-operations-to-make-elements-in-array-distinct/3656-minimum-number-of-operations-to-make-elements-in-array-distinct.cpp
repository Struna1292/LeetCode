class Solution {
public:
    bool isDistinct(map<int,int>& mp)
    {
        for (auto itr = mp.begin(); itr != mp.end(); itr++)
        {
            if (itr->second >= 2)
            {
                return false;
            }
        }

        return true;
    }

    int minimumOperations(vector<int>& nums) {
        
        map<int,int> mp;

        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }

        if (isDistinct(mp))
        {
            return 0;
        }

        int output = 0;

        for (int i = 0; i < nums.size(); i+=3)
        {
            if (nums.size()-i >= 3)
            {
                for (int j = 0; j < 3; j++)
                {
                    mp[nums[i+j]]--;
                }
            }
            else
            {
                for (int j = 0; j < nums.size()-i; j++)
                {
                    mp[nums[i+j]]--;
                }
            }
            output++;

            if (isDistinct(mp))
            {
                break;
            }
        }

        return output;
    }
};