class Solution {
public:
    string reversePrefix(string s, int k) {
        k--;
        int i = 0;
        while (i < k) {
            swap(s[i], s[k]);
            i++;
            k--;
        }

        return s;
    }
};