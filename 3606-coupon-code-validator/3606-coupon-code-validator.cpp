class Solution {
public:
    struct Item {
        string code;
        string businessLine;
        Item(string c, string bL) {
            code = c;
            businessLine = bL;
        }
    };

    struct Comparator {
        unordered_map<string, int> um;
        Comparator(unordered_map<string, int> u) {
            um = u;
        }

        bool operator()(Item& a, Item& b) {
            if (a.businessLine == b.businessLine) {
                return a.code < b.code;
            }

            return um[a.businessLine] < um[b.businessLine];
        }
    };

    unordered_set<char> prepareValidChars() {
        unordered_set<char> validChars;
        validChars.insert('_');

        for (int i = 'a'; i <= 'z'; i++) {
            validChars.insert(i);
        }

        for (int i = 'A'; i <= 'Z'; i++) {
            validChars.insert(i);
        }

        for (int i = '0'; i <= '9'; i++) {
            validChars.insert(i);
        }      

        return validChars;
    }

    bool validateChars(string& s, unordered_set<char>& validChars) {
        if (s.length() == 0) {
            return false;
        }

        for (int i = 0; i < s.length(); i++) {
            if (!validChars.contains(s[i])) {
                return false;
            }
        }

        return true;
    }

    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {

        unordered_map<string, int> um;
        um["electronics"] = 0;
        um["grocery"] = 1;
        um["pharmacy"] = 2;
        um["restaurant"] = 3;
        
        unordered_set<char> validChars = prepareValidChars();

        vector<Item> items;

        for (int i = 0; i < code.size(); i++) {
            if (!isActive[i]) {
                continue;
            }

            if (!um.contains(businessLine[i])) {
                continue;
            }

            if (!validateChars(code[i], validChars)) {
                continue;
            }

            items.push_back(Item(code[i], businessLine[i]));
        }

        sort(begin(items), end(items), Comparator{um});

        vector<string> output;
        for (int i = 0; i < items.size(); i++) {
            output.push_back(items[i].code);
        }

        return output;
    }
};