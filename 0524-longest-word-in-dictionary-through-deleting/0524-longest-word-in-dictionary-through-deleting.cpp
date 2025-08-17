class Solution {
public:
    struct comparator {
        bool isLexicographicalSmaller(string& a, string& b) {
            for (int i = 0; i < a.length(); i++) {
                if (a[i] == b[i]) {
                    continue;
                }
                else if (a[i] < b[i]) {
                    return true;
                }
                else {
                    return false;
                }
            }

            return false;
        } 

        bool operator()(string& a, string& b) {
            if (a.length() == b.length()) {
                return isLexicographicalSmaller(a, b);
            }

            return a.length() > b.length();
        }
    };

    string findLongestWord(string s, vector<string>& dictionary) {
        
        unordered_map<char, vector<int>> um; // letter and vector of indexes

        for (int i = 0; i < s.length(); i++) {
            um[s[i]].push_back(i);
        }

        sort(begin(dictionary), end(dictionary), comparator());

        for (int currWord = 0; currWord < dictionary.size(); currWord++) {

            string currString = dictionary[currWord];

            int wordI = 0;
            int wordJ = currString.length()-1;

            if (um[currString[wordI]].size() == 0 || um[currString[wordJ]].size() == 0) {
                continue;
            }

            for (int i = um[currString[wordI]][0]; i < s.length(); i++) {
                if (s[i] == currString[wordI]) {
                    wordI++;
                }

                if (wordI == currString.length()) {
                    return currString;
                }
            }
        }

        return "";
    }   
};