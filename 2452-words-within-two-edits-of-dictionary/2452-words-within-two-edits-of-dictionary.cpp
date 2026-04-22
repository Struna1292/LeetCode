class Solution {
public:
    bool compareWithChange(const string& s1, const string& s2, int k) {
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] != s2[i]) {
                k--;
            }

            if (k < 0) {
                return false;
            }
        }

        return true;
    }

    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> output;
        for (int i = 0; i < queries.size(); i++) {
            const string& queryWord = queries[i];

            for (int j = 0; j < dictionary.size(); j++) {
                const string& dictWord = dictionary[j];

                if (compareWithChange(queryWord, dictWord, 2)) {
                    output.push_back(queryWord);
                    break;
                }
            }
        }

        return output;
    }
};