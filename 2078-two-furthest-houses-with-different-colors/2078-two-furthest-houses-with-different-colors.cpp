class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int output = -1;

        for (int i = 0; i < colors.size(); i++) {
            for (int j = colors.size()-1; i < j; j--) {
                if (colors[i] != colors[j]) {
                    if (j - i > output) {
                        output = j - i;
                    }
                    break;
                }
            }
        }

        return output;
    }
};