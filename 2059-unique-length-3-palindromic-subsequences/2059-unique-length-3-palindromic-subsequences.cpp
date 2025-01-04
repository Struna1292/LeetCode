class Solution {
public:
    int countPalindromicSubsequence(string s) {
        
        set<string> st;

        vector<vector<int>> indexes(26, vector<int>());

        for (int i = 0; i < s.length(); i++)
        {
            if (indexes[s[i]-'a'].size() >= 1)
            {
                int index = indexes[s[i]-'a'][indexes[s[i]-'a'].size()-1] + 1;
                for (int j = index; j < i; j++)
                {
                    string curr;
                    curr.push_back(s[i]);
                    curr.push_back(s[j]);
                    curr.push_back(s[i]);
                    st.insert(curr);
                }

                if (indexes[s[i]-'a'].size() == 2)
                {
                    string curr;
                    curr.push_back(s[i]);
                    curr.push_back(s[i]);
                    curr.push_back(s[i]);
                    st.insert(curr);
                }
            }

            indexes[s[i]-'a'].push_back(i);
        }

        return st.size();
    }
};