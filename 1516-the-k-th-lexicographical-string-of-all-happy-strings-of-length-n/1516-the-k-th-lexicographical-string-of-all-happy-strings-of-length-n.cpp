class Solution {
public:
    void helper(string& curr, int& limit, int& count, string& output, int index)
    {
        if (output != "")
        {
            return;
        }

        if (index == limit)
        {
            count--;
            if (count == 0)
            {
                output = curr;
            }
            return;
        }

        for (int i = 'a'; i <= 'c'; i++)
        {
            if (index == 0 || curr[index-1] != i)
            {
                curr[index] = i;
                helper(curr, limit, count, output, index+1);
                curr[index] = ' ';
            }
        }
    }

    string getHappyString(int n, int k) {
        string output = "";
        string curr(n, ' ');

        helper(curr, n, k, output, 0);

        return output;
    }
};