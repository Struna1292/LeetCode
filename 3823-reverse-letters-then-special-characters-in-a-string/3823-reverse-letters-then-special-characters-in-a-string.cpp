class Solution {
public:
    void reverseChars(string& s, unordered_set<char>& us) {
        int i = 0;
        int j = s.length()-1;
        while (i < j) {
            if (!us.contains(s[i])) {
                i++;
                continue;
            }
            else if (!us.contains(s[j])) {
                j--;
                continue;
            }

            swap(s[i], s[j]);
            i++;
            j--;
        }
    }

    string reverseByType(string s) {
        unordered_set<char> letters;
        for (int i = 'a'; i <= 'z'; i++) {
            letters.insert(i);
        }

        unordered_set<char> specialChars = {'!','@','#','$','%','^','&','*','(',')'};

        reverseChars(s, letters);
        reverseChars(s, specialChars);

        return s;
    }
};