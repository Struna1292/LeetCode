class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string output;

        for (int i = 0; i < words.size(); i++) {
            int currWeight = 0;
            for (int j = 0; j < words[i].length(); j++) {
                currWeight += weights[words[i][j] - 'a'];
            }

            char c = 'z' - (currWeight % 26);

            output.push_back(c);
        }

        return output;
    }
};