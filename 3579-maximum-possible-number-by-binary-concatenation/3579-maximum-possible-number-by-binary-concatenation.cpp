class Solution {
public:
    int maxGoodNumber(vector<int>& nums) {
        
        vector<string> binary;

        binary.push_back(bitset<64>(nums[0]).to_string());
        binary.push_back(bitset<64>(nums[1]).to_string());
        binary.push_back(bitset<64>(nums[2]).to_string());

        for (int i = 0; i < binary.size(); i++)
        {
            string curr;

            bool start = false;

            for (int j = 0; j < 64; j++)
            {
                if (binary[i][j] == '1')
                {
                    start = true;
                }
                if (start)
                {
                    curr.push_back(binary[i][j]);
                }
            }

            binary[i] = curr;
        }

        int output = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < nums.size(); j++)
            {
                if (j != i)
                {
                    for (int k = 0; k < nums.size(); k++)
                    {
                        if (k != i && k != j)
                        {
                            cout << i+1 << " " << j+1 << " " << k+1 << endl;

                            string combination = binary[i] + binary[j] + binary[k];

                            string curr(64, '0');
                            int m = 63;
                            for (int l = combination.length()-1; l >= 0; l--)
                            {
                                curr[m] = combination[l];
                                m--;
                            }

                            std::bitset<64> bitset(curr);
                            int check = static_cast<int64_t>(bitset.to_ullong());

                            if (check > output)
                            {
                                output = check;
                            }
                        }
                    }
                }
            }
        }

        return output;
    }
};