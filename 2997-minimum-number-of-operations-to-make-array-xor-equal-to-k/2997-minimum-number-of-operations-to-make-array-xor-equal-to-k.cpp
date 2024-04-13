class Solution {
public:
    void convertNumberToBinaryString(int num, string& representation)
    {
        int i = 0;

        while (num > 0)
        {
            if ((num & 1) == 1)
            {
                representation[i] = '1';
            }
            num >>= 1;
            i++;
        }
    }

    int minOperations(vector<int>& nums, int k) {

        int n = nums.size();

        vector<string> binary(n, "00000000000000000000000000000000");
        vector<int> ones(32, 0);

        for (int i = 0; i < nums.size(); i++)
        {
            convertNumberToBinaryString(nums[i], binary[i]);

            for (int j = 0; j < 32; j++)
            {
                if (binary[i][j] == '1')
                {
                    ones[j]++;
                }
            }
        }

        string kBinary = "00000000000000000000000000000000";

        convertNumberToBinaryString(k, kBinary);

        int output = 0;

        for (int i = 0; i < 32; i++)
        {
            if (kBinary[i] == '0')
            {
                if (ones[i] % 2 != 0)
                {
                    output++;
                }
            }
            else
            { 
                if (ones[i] % 2 == 0)
                {
                    output++;
                }
            }
        }

        return output;
    }
};