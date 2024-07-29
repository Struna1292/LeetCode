class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        
        map<vector<int>, int> mp;

        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i; j <= nums.size(); j++)
            {
                int currCounter = k;
                vector<int> curr;
                for (int l = i; l < j; l++)
                {
                    if (nums[l] % p == 0 && currCounter == 0)
                    {
                        break;
                    }
                    else if (nums[l] % p == 0)
                    {
                        currCounter--;
                    }
                    curr.push_back(nums[l]);
                }

                mp[curr]++;
            }
        }


        return mp.size()-1;
    }
};