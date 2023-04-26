class Solution {
public:
    string countAndSay(int n) {

        string output;
        if (n == 1)
        {
            return "1";
        }
        else
        {
            output = "11";
        }
        int counter = 0;
        for (int i = 2; i < n; i++)
        {
            string curr;
            counter = 1;
            char prev = output[0];
            for (int j = 1; j < output.size(); j++)
            {
                if (output[j] != prev)
                {
                    curr.push_back(counter + '0');
                    curr.push_back(prev);
                    counter = 1;
                }
                else
                {
                    counter++;
                }
                if (j+1 == output.size())
                {
                    curr.push_back(counter + '0');
                    curr.push_back(output[j]);
                }
                prev = output[j];
            }

            output = curr;
        }
        return output;
    }
};