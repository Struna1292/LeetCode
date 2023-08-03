class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;

        for (int i = 0; i < tokens.size(); i++)
        {
            if (tokens[i] == "+")
            {
                int num1 = stoi(st.top());
                st.pop();
                int num2 = stoi(st.top());
                st.pop();
                st.push(to_string(num1 + num2));
            }
            else if (tokens[i] == "-")
            {
                int num1 = stoi(st.top());
                st.pop();
                int num2 = stoi(st.top());
                st.pop();
                st.push(to_string(num2 - num1));
            }
            else if (tokens[i] == "/")
            {
                int num1 = stoi(st.top());
                st.pop();
                int num2 = stoi(st.top());
                st.pop();
                st.push(to_string(num2 / num1));
            }
            else if (tokens[i] == "*")
            {
                int num1 = stoi(st.top());
                st.pop();
                int num2 = stoi(st.top());
                st.pop();
                st.push(to_string(num1 * num2));
            }
            else
                st.push(tokens[i]);
        }

        return stoi(st.top());
    }
};