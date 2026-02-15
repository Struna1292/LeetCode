class Solution {
public:
    string addBinary(string a, string b) {
        if (a.length() < b.length()) {
            swap(a, b);
        }

        bool carry = false;
        int i = a.length() - 1;
        int j = b.length() - 1;

        while (j >= 0) {
            int sum = (a[i] - '0') + (b[j] - '0') + carry;
            a[i] = (sum % 2) + '0';
            carry = sum / 2;

            i--;
            j--;
        }
        
        while (i >= 0 && carry) {
            int sum = (a[i] - '0') + carry;
            a[i] = (sum % 2) + '0';
            carry = sum / 2;
            i--;
        }

        if (carry) {
            a.insert(a.begin(), '1');
        }

        return a;
    }
};