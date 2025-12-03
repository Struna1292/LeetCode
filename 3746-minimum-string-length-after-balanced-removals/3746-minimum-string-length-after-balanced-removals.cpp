class Solution {
public:
    int minLengthAfterRemovals(string s) {
        stack<char> st;

        for (int i = 0; i < s.length(); i++) {
            if (st.empty() || st.top() == s[i]) {
                st.push(s[i]);
            }
            else {
                st.pop();
            }
        }

        return st.size();
    }
};