class Solution {
public:
    int binaryStringToInt(string& s)
    {
        bitset<64> bitset(s);
        return static_cast<int64_t>(bitset.to_ullong());
    }

    void changeCount(int* arr, string& s, int type)
    {
        if (type == 1)
        {
            for (int i = 0; i < 64; i++)
            {
                if (s[i] == '1')
                {
                    arr[i]++;
                }
            }
        }
        else if (type == -1)
        {
            for (int i = 0; i < 64; i++)
            {
                if (s[i] == '1')
                {
                    arr[i]--;
                }
            }
        }
    }

    string generateBinaryString(int* arr)
    {
        string s(64, '0');

        for (int i = 0; i < 64; i++)
        {
            if (arr[i] > 0)
            {
                s[i] = '1';
            }
        }

        return s;
    }    

    int minimumSubarrayLength(vector<int>& nums, int k) {
        vector<string> binary;

        for (int n : nums)
        {
            binary.push_back(bitset<64>(n).to_string());
        }


        int curr[64] = { 0 };

        int output = -1;
        int index = 0;
        for (int i = 0; i < binary.size(); i++)
        {
            changeCount(curr, binary[i], 1);

            string check = generateBinaryString(curr);

            int currNum = binaryStringToInt(check);

            if (currNum >= k)
            {
                int l = index;

                while (l <= i)
                {
                    changeCount(curr, binary[l], -1);

                    string check2 = generateBinaryString(curr);

                    int checkNum = binaryStringToInt(check2);

                    if (checkNum >= k)
                    {
                        if (l == i)
                        {
                            return 1;
                        }   
                        index++;
                        l++;
                    }
                    else
                    {
                        changeCount(curr, binary[l], 1);
                        break;
                    }
                }

                if (output == -1 || (i - index + 1) < output)
                {
                    output = i - index + 1;
                }
            }
            
        }

        return output;
    }
};