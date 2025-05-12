class Solution {
public:
    void helper(vector<int>& digits, vector<bool>& used, int currLength, int curr, set<int>& st)
    {
        if (currLength == 3)
        {
            if (curr >= 100 && curr <= 999 && curr % 2 == 0)
            {
                st.insert(curr);
            }
            return;
        }

        for (int i = 0; i < digits.size(); i++)
        {
            if (!used[i])
            {
                used[i] = true;
                int currCp = (curr * 10) + digits[i];
                helper(digits, used, currLength+1, currCp, st);
                used[i] = false;
            }
        }
    }

    vector<int> findEvenNumbers(vector<int>& digits) {
        
        vector<bool> used(digits.size(), false);
        set<int> st;
        
        helper(digits, used, 0, 0, st);

        vector<int> output;

        for (auto itr = st.begin(); itr != st.end(); itr++)
        {
            output.push_back(*itr);
        }

        return output;
    }
};