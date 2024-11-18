class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        
        vector<int> output;

        int direction = 1;
        if (k < 0)
        {
            direction = -1;
            k *= -1;
        }

        for (int i = 0; i < code.size(); i++)
        {
            int curr = 0;
            int j = i;

            int currK = k;

            while (currK > 0)
            {
                currK--;
                if (direction == 1)
                {
                    j++;
                    if (j == code.size())
                    {
                        j = 0;
                    }
                }
                else
                {
                    j--;
                    if (j == -1)
                    {
                        j = code.size()-1;
                    }
                }

                curr += code[j];
            }
            output.push_back(curr);
        }

        return output;
    }
};