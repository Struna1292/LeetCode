class Solution {
public:
    bool isLetter(char c) {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            return true;
        }
        return false;
    }

    char changeLetter(char c) {
        if (c >= 'a' && c <= 'z') {
            return c - 32;
        }
        else {
            return c + 32;
        }
    }

    void helper(int i, string s, set<string>& combinations) {

        for (i; i < s.length(); i++) {
            if (isLetter(s[i])) {
                helper(i+1, s, combinations);
                combinations.insert(s);

                s[i] = changeLetter(s[i]);
                helper(i+1, s, combinations);
            }
            combinations.insert(s);
        }

    }

    vector<string> letterCasePermutation(string s) {        
        set<string> combinations;
        helper(0, s, combinations);

        vector<string> output;
        for (auto itr = combinations.begin(); itr != combinations.end(); itr++) {
            output.push_back(*itr);
        }

        return output;
    }
};