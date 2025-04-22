class Solution {
public:
    void helper(vector<int>& digits, vector<bool>& used, set<vector<int>>& st, vector<int>& curr, int currIndex)
    {
        if (currIndex == 3)
        {
            st.insert(curr);
            return;
        }

        for (int i = 0; i < digits.size(); i++)
        {
            if (!used[i])
            {
                used[i] = true;
                curr[currIndex] = digits[i];
                helper(digits, used, st, curr, currIndex+1);
                used[i] = false;
            }
        }
    }

    int totalNumbers(vector<int>& digits) {
        
        set<vector<int>> st;

        vector<bool> used(digits.size(), false);

        vector<int> curr(3, -1);

        helper(digits, used, st, curr, 0);

        int output = 0;

        for (auto itr = st.begin(); itr != st.end(); itr++)
        {
            if ((*itr)[0] == 0) // if the first digit is 0 then length cannot be 3
            {
                continue;
            }

            int num = (*itr)[0] * 100 + (*itr)[1] * 10 + (*itr)[2];

            cout << num << endl;

            if (num % 2 == 0)
            {
                output++;
            }
        }
        
        return output;
    }
};