class Solution {
public:
    void addOne(string& s) {
        for (int i = s.length()-1; i >= 0; i--) {
            if (s[i] == '1') {
                s[i] = '0';
            }
            else {
                s[i] = '1';
                return;
            }
        }

        s.insert(s.begin(), '1');
    }

    void divideByTwo(string& s) {
        for (int i = s.length()-1; i > 0; i--) {
            s[i] = s[i-1];
        }
        s[0] = '0';
    }

    bool isOne(string& s) {
        for (int i = 0; i < s.length()-1; i++) {
            if (s[i] == '1') {
                return false;
            }
        }

        return s[s.length()-1] == '1';
    }

    int numSteps(string s) {
        if (s == "1") {
            return 0;
        }

        int output = 0;
        
        while (!isOne(s)) {
            if (s[s.length()-1] == '1') {
                addOne(s);
            }
            else {
                divideByTwo(s);
            }
            output++;
        }
        
        return output;
    }
};