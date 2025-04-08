class Solution {
public:

    int minimumOperations(vector<int>& nums) {
        
        map<int,int> mp;

        int i = nums.size()-1;

        if (nums.size() % 3 == 1)
        {
            mp[nums[i]]++;
            i--;
        }
        else if (nums.size() % 3 == 2)
        {
            mp[nums[i]]++;
            i--;
            mp[nums[i]]++;

            if (mp[nums[i]] > 1)
            {
                return (nums.size()/3)+1;
            }
            i--;
        }

        for (; i >= 0; i-=3)
        {
            for (int j = i; j > i-3; j--)
            {
                mp[nums[j]]++;
                if (mp[nums[j]] > 1)
                {
                    return (i+1)/3;
                }
            }
        }

        return 0;
    }
};