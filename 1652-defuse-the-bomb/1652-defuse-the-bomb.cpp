class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> output(code.size(), 0);

        for (int i = 0; i < code.size(); i++)
        {
            int curr = 0;

            int counter = 0;
            int j = i;

            while (counter < abs(k))
            {
                if (k > 0)
                {
                    if (j+1 == code.size())
                    {
                        j = 0;
                    }
                    else
                    {
                        j++;
                    }
                }
                else if (k < 0)
                {
                    if (j-1 < 0)
                    {
                        j = code.size()-1;
                    }
                    else
                    {
                        j--;
                    }
                }

                curr += code[j];
                counter++;
            }

            output[i] = curr;
        }


        return output;
    }
};