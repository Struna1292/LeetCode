class Solution {
public:
    int minPartitions(string n) {
        
        char biggestDigit = n[0];
        for (int i = 1; i < n.length(); i++) {
            biggestDigit = max(n[i], biggestDigit);
        }

        return biggestDigit - '0';
    }
};