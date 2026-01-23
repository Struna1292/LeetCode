class Solution {
public:
    bool isLowerCaseEnglishLetter(char c) {
        if (c >= 'a' && c <= 'z') {
            return true;
        }
        return false;
    }

    void reverseDeque(deque<char>& dq) {
        int i = 0;
        int j = dq.size()-1;
        while (i < j) {
            swap(dq[i], dq[j]);
            i++;
            j--;
        }
    }

    void appendItself(deque<char>& dq) {
        int length = dq.size();
        for (int i = 0; i < length; i++) {
            dq.push_back(dq[i]);
        }
    }

    string processStr(string s) {
        deque<char> dq;

        for (int i = 0; i < s.length(); i++) {
            if (isLowerCaseEnglishLetter(s[i])) {
                dq.push_back(s[i]);
            }
            else if (s[i] == '*' && !dq.empty()) {
                dq.pop_back();
            }
            else if (s[i] == '#') {
                appendItself(dq);
            }
            else if (s[i] == '%') {
                reverseDeque(dq);
            }
        }

        string output;
        for (int i = 0; i < dq.size(); i++) {
            output.push_back(dq[i]);
        }

        return output;
    }
};