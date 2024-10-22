class Solution {
public:
    vector<string> stringSequence(string target) {
        
        vector<string> output;

        string curr;

        for (int i = 0; i < target.length(); i++)
        {
            curr.push_back('a');

            while (curr[curr.length()-1] != target[i])
            {
                output.push_back(curr);
                curr[curr.length()-1]++;
            }

            output.push_back(curr);
        }

        return output;
    }
};