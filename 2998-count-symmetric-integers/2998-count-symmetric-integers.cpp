class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        
        int counter = 0;

        for (int i = low; i <= high; i++)
        {
            string curr = to_string(i);

            if (curr.length() % 2 == 0)
            {
                int left = 0;
                int right = 0;
                for (int j = 0; j < curr.length(); j++)
                {
                    if (j < (curr.length()/2))
                    {
                        left += curr[j] - '0';
                    }
                    else
                    {
                        right += curr[j] - '0';
                    }
                }

                if (left == right)
                {
                    counter++;
                }
            }
        }

        return counter;
    }
};