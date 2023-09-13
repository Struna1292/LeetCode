class Solution {
public:
    bool binarySearch(vector<int>& nums, int target)
    {
        int left = 0;
        int right = nums.size()-1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
            {
                return true;
            }

            if (nums[mid] < target)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        return false;
    }

    int minDeletions(string s) {
        vector<int> alph(26, 0);

        for (int i = 0; i < s.length(); i++)
        {
            alph[s[i]-'a']++;
        }

        sort(begin(alph), end(alph), greater<int>());

        int output = 0;
        int i = 0;

        while (i+1 < 26)
        {
            if (alph[i] == alph[i+1])
            {
                if (alph[i] == 0)
                {
                    break;
                }

                int j = 0;
                for (j = alph[i]-1; j > 0; j--)
                {
                    if (!binarySearch(alph, j))
                    {
                        break;
                    }
                }
                output += alph[i] - j;

                if (alph[i] != j)
                {
                    alph[i] = j;
                }
                else
                {
                    i++;
                }
                sort(begin(alph), end(alph), greater<int>());
            }
            else
            {
                i++;
            }
        }

        return output;
    }
};