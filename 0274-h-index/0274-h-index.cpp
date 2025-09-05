class Solution {
public:
    int min(int a, int b) {
        if (a < b) {
            return a;
        }
        return b;
    }

    int hIndex(vector<int>& citations) {
        sort(begin(citations), end(citations));

        int output = 0;
        for (int i = 0; i < citations.size(); i++) {
            int curr = min(citations[i], (citations.size()-i));

            output = max(output, curr);
        }

        return output;
    }
};