class Solution {
public:
    int calPoints(vector<string>& operations) {

        stack<int> st;

        for (int i = 0; i < operations.size(); i++)
        {
            if (operations[i][0] == '+')
            {
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.push(num1);
                st.push(num1+num2);
            }
            else if (operations[i][0] == 'C')
            {
                st.pop();
            }
            else if (operations[i][0] == 'D')
            {
                int num = st.top() * 2;
                st.push(num);
            }
            else
            {
                int num = stoi(operations[i]);
                st.push(num);
            }
        }

        int total = 0;
        while (!st.empty())
        {
            total += st.top();
            st.pop();
        }

        return total;
    }
};