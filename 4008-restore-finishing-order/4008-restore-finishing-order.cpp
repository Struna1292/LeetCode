class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        
        unordered_set<int> us;

        for (int i = 0; i < friends.size(); i++) {
            us.insert(friends[i]);
        }

        int currPosition = 0;
        vector<int> output(friends.size(), 0);
        for (int i = 0; i < order.size(); i++) {
            if (us.find(order[i]) != us.end()) {
                output[currPosition] = order[i];
                currPosition++;
            }
        }

        return output;
    }
};