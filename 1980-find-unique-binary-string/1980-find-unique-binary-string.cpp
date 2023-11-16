class Solution {
public:

    string findDifferentBinaryString(vector<string>& nums) {
        vector<int> nums1;

        for (int i = 0; i < nums.size(); i++)
        {
            int curr = 0;
            for (int j = 0; j < nums[i].length(); j++)
            {
                curr <<= 1;
                if (nums[i][j] == '1')
                {
                    curr |= 1;
                }
            }
            nums1.push_back(curr);
        }

        sort(begin(nums1), end(nums1));

        string output;

        for (int i = 0; i < nums1[nums1.size()-1]; i++)
        {
            if (nums1[i] != i)
            {
                while (i > 0)
                {
                    if ((i & 1) == 1)
                    {
                        output.push_back('1');
                    }
                    else
                    {
                        output.push_back('0');
                    }
                    i >>= 1;
                }

                int n = output.length();
                for (int j = 0; j < nums[0].length() - n; j++)
                {
                    output.push_back('0');
                }

                int j = 0;
                int k = output.length()-1;
                while (j < k)
                {
                    swap(output[j], output[k]);
                    j++;
                    k--;
                }

                return output;
            }
        }

        int i = nums1[nums1.size()-1]+1;

        while (i > 0)
        {
            if ((i & 1) == 1)
            {
                output.push_back('1');
            }
            else
            {
                output.push_back('0');
            }
            i >>= 1;
        }

        int n = output.length();
        for (int j = 0; j < nums[0].length() - n; j++)
        {
            output.push_back('0');
        }

        int j = 0;
        int k = output.length()-1;
        while (j < k)
        {
            swap(output[j], output[k]);
            j++;
            k--;
        }


        return output;
    }
};