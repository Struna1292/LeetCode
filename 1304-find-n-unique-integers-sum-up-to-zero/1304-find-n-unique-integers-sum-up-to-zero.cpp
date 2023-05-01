class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> output;

        if (n % 2 != 0)
        {
            output.push_back(0);
        }

        for (int i = 1; i <= n / 2; i++)
        {
            output.push_back(i);
            output.push_back(-i);
        }
        return output;
    }
};