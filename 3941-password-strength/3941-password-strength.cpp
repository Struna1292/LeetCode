class Solution {
public:
    int passwordStrength(string password) {
        unordered_set<char> us;

        for (int i = 0; i < password.length(); i++) {
            us.insert(password[i]);
        }

        int output = 0;

        for (int i = 0; i < 26; i++) {
            if (us.contains('a' + i)) {
                output += 1;
            }

            if (us.contains('A' + i)) {
                output += 2;
            }
        }

        for (char c = '0'; c <= '9'; c++) {
            if (us.contains(c)) {
                output += 3;
            }
        }

        string specials = "!@#$";
        for (int i = 0; i < specials.size(); i++) {
            if (us.contains(specials[i])) {
                output += 5;
            }
        }

        return output;
    }
};