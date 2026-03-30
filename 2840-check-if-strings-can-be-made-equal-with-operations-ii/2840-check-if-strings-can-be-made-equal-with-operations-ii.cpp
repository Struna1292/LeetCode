class Solution {
public:
    bool checkStrings(string s1, string s2) {
        unordered_map<char, int> even;
        unordered_map<char, int> odd;

        for (int i = 0; i < s1.length(); i++) {
            if (i % 2 == 0) {
                even[s1[i]]++;
                even[s2[i]]--;
            }
            else {
                odd[s1[i]]++;
                odd[s2[i]]--;
            }
        }

        for (auto itr = even.begin(); itr != even.end(); itr++) {
            if (itr->second != 0) {
                return false;
            }
        }

        for (auto itr = odd.begin(); itr != odd.end(); itr++) {
            if (itr->second != 0) {
                return false;
            }
        }

        return true;
    }
};