class Solution {
public:
    void verifyCurr(string& curr, stack<string>& st)
    {
        if (curr.length() >= 1)
        {
            if (curr == "..")
            {
                if (st.size() >= 1)
                {
                    st.pop();
                }
            }
            else
            {
                if (curr != ".")
                {
                    st.push(curr);  
                }
            }
        }
        curr = "";
    }

    string simplifyPath(string path) {
        
        stack<string> st;

        string curr;

        for (int i = 0; i < path.length(); i++)
        {
            if (path[i] == '/')
            {
                verifyCurr(curr, st);
            }
            else
            {
                curr.push_back(path[i]);
            }
        }

        verifyCurr(curr, st);
        
        string output;

        while (!st.empty())
        {
            output = "/" + st.top() + output;
            st.pop();
        }

        if (output.length() < 1)
        {
            output = "/";
        }

        return output;
    }
};