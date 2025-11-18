class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        if (bits.size() == 1 || bits[bits.size()-2] == 0) {
            return true;
        }

        for (int i = 0; i < bits.size(); i++) {
            if (bits[i] == 1) {
                i++;
            }
            else if (i+1 == bits.size()) {
                return true;
            }
        }

        return false;
    }
};