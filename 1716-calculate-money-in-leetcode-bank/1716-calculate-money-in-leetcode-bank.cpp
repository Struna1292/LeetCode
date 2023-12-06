class Solution {
public:
    int totalMoney(int n) {
        int output = 0;

        int prev = 0;
        int curr = 1;

        for (int i = 0; i < n; i++)
        {
            if ((i+7) % 7 == 0)
            {
                curr = prev+1;
                prev = curr;
            }
            output += curr;
            curr++;
        }

        return output;
    }
};