class Solution {
public:
    string firstOperation(string& s, int& a) {
        string curr = s;

        for (int i = 1; i < curr.length(); i+=2) {
            curr[i] += a;
            if (curr[i] > '9') {
                curr[i] -= 10;
            }
        }

        return curr;
    }

    string secondOperation(string& s, int& b) {
        string curr = s;

        for (int i = 0; i < curr.length(); i++) {
            curr[i] = s[(i+b) % s.length()];
        }

        return curr;
    }

    void helper(string& s, int& a, int& b, unordered_set<string>& us, string& output) {
        if (us.contains(s)) {
            return;
        }

        output = min(output, s);
        
        us.insert(s);

        string first = firstOperation(s, a);
        string second = secondOperation(s, b);

        helper(first, a, b, us, output);
        helper(second, a, b, us, output);
    }

    string findLexSmallestString(string s, int a, int b) {
        unordered_set<string> us;

        string output(s.length(), '9');

        helper(s, a, b, us, output);

        return output;
    }
};