class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        
        int num = 1;
        vector<string> output;

        for (int i = 0; i < target.size(); i++)
        {
            while (num < target[i])
            {
                output.push_back("Push");
                output.push_back("Pop");
                num++;
            }
            output.push_back("Push");
            num++;
        }

        return output;
    }
};