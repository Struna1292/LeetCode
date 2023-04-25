class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> output;
        int counter = 0;
        for (int i = 0; i <= n; i++)
        {
            counter = 0;
            int curr = i;
            while (curr > 0)
            {
                if (curr & 1)
                {
                    counter++;
                }
                curr >>= 1;
            }
            output.push_back(counter);
        }
        return output;
    }
};