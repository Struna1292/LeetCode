class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
        vector<int> ignoreIndexes;
        stack<int> st;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == ')') {
                if (s[i] == '(') {
                    st.push(i);
                }
                else {
                    if (st.empty()) {
                        ignoreIndexes.push_back(i);
                    }
                    else {
                        st.pop();
                    }
                }
            }
        }

        while (!st.empty()) {
            ignoreIndexes.push_back(st.top());
            st.pop();
        }

        sort(begin(ignoreIndexes), end(ignoreIndexes));

        string output;
        int j = 0;
        for (int i = 0; i < s.length(); i++) {
            if (j < ignoreIndexes.size() && i == ignoreIndexes[j]) {
                j++;
                continue;
            }

            output.push_back(s[i]);
        }

        return output;
    }
};