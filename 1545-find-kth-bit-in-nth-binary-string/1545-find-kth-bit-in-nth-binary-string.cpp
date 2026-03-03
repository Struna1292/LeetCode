class Solution {
public:
    void invert(string& s) {
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '1') {
                s[i] = '0';
            }
            else {
                s[i] = '1';
            }
        }
    }

    void reverse(string& s) {
        int i = 0;
        int j = s.length()-1;
        while (i < j) {
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }

    char findKthBit(int n, int k) {
        
        string s = "0";
        while (n > 0) {
            string curr = s;
            invert(curr);
            reverse(curr);

            s.push_back('1');

            s += curr;

            if (k-1 < s.length()) {
                break;
            }

            n--;
        }

        return s[k-1];
    }
};