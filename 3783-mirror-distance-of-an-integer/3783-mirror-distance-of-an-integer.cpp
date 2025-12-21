class Solution {
public:
    int mirrorDistance(int n) {
        string s = to_string(n);

        int i = 0;
        int j = s.length()-1;
        while (i < j) {
            swap(s[i], s[j]);
            i++;
            j--;
        }

        return  abs(n - stoi(s));
    }
};