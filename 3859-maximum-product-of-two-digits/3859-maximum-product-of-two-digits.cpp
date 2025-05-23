class Solution {
public:
    int maxProduct(int n) {
        string s = to_string(n);

        sort(begin(s), end(s));

        cout << s << endl;

        return (s[s.length()-1]-'0') * (s[s.length()-2]-'0');
    }
};