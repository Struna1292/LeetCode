class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        
        int curr = derived[0];

        for (int i = 1; i < derived.size(); i++)
        {
            curr ^= derived[i];
        }

        return !curr;
    }
};