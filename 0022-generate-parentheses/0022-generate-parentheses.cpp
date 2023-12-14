class Solution {
public:
    void helper(set<string>& output, string curr, int l, int r)
    {
        if (l == 0 && r == 0)
        {
            output.insert(curr);
            return;
        }
        else if (r < l)
        {
            return;
        }

        if (l > 0 && r > 0)
        {
            helper(output, curr+"(", l-1, r);
            helper(output, curr+")", l, r-1);
        }

        if (r > 0)
        {
            helper(output, curr+")", l, r-1);
        }
    }

    vector<string> generateParenthesis(int n) {

        set<string> o;

        helper(o, "", n, n);

        vector<string> output;

        for (auto& str : o)
        {
            output.push_back(str);
        }

        return output;
    }
};