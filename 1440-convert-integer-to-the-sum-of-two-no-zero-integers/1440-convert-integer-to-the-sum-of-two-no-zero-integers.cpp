class Solution {
public:
    bool containsZero(int n)
    {
        string s = to_string(n);

        for (char c : s)
        {
            if (c == '0')
            {
                return true;
            }
        }
        
        return false;
    }

    vector<int> getNoZeroIntegers(int n) {

        int i = 1;
        int j = n-1;

        while (i <= j)
        {
            if (!containsZero(i) && !containsZero(j))
            {
                return {i, j};
            }

            i++;
            j--;
        }

        return {};
    }
};