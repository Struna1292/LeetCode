class Solution {
public:
    vector<int> shortestToChar(string s, char c) {

        vector<int> indexes;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == c)
            {
                indexes.push_back(i);
            }
        }


        vector<int> output(s.length(), 0);
        int index = 0;
        for (int i = 0; i < output.size(); i++)
        {
            for (int j = index+1; j < indexes.size(); j++)
            {
                if (abs(i - indexes[index]) > abs(i - indexes[j]))
                {
                    index = j;
                }
                else
                {
                    break;
                }
            }
            output[i] = abs(i - indexes[index]);
        }

        return output;
    }
};