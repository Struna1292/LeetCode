class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        
        set<string> st;

        for (string s : emails)
        {
            bool domain = false;
            bool plus = false;
            string curr;
            for (int i = 0; i < s.length(); i++)
            {   
                if (!domain)
                {
                    if (s[i] == '@')
                    {
                        curr.push_back(s[i]);
                        domain = true;
                        continue;
                    }
                    if (!plus)
                    {
                        if (s[i] == '+')
                        {
                            plus = true;
                        }
                        else if (s[i] != '.')
                        {
                            curr.push_back(s[i]);
                        }
                    }
                }
                else
                {
                    curr.push_back(s[i]);
                }
            }

            st.insert(curr);
        }

        return st.size();
    }
};