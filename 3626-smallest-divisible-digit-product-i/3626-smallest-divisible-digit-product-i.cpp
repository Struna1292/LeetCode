class Solution {
public:
    int smallestNumber(int n, int t) {
        
        while (true)
        {
            string curr = to_string(n);

            int product = 1;
            for (int i = 0; i < curr.length(); i++)
            {
                product *= curr[i] - '0';
            }

            if (product % t == 0)
            {
                return n;
            }
            else
            {
                n++;
            }
        }
        
        return -1;
    }
};