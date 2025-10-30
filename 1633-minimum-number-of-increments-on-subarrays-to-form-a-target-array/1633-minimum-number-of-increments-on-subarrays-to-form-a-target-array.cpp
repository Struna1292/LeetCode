class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int output = 0;
        
        for (int i = 1; i < target.size(); i++) {
            if (target[i-1] > target[i]) {
                output += target[i-1] - target[i];
            }
        }
        output += target[target.size()-1];

        return output;
    }
};