class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {

        int sum = 0;
        for (int i = 0; i < apple.size(); i++) {
            sum += apple[i];
        }
        
        sort(begin(capacity), end(capacity), greater<int>());

        for (int i = 0; i < capacity.size(); i++) {
            sum -= capacity[i];
            if (sum <= 0) {
                return i+1;
            }
        }

        return -1;
    }
};