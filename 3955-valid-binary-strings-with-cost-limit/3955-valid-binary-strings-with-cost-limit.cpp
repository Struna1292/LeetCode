class Solution {
public:
    void helper(string& curr, int index, int k, unordered_set<string>& us) {
        if (k < 0) {
            return;
        }
        
        us.insert(curr);

        for (int i = index; i < curr.length(); i++) {
            helper(curr, i+1, k, us);

            if (i == 0 || (i > 0 && curr[i-1] == '0')) {
                curr[i] = '1';
                helper(curr, i+1, k-i, us);
                curr[i] = '0';
            }
        }
    }

    vector<string> generateValidStrings(int n, int k) {
        string s(n, '0');
        unordered_set<string> us;

        helper(s, 0, k, us);

        vector<string> output;

        for (auto itr = us.begin(); itr != us.end(); itr++) {
            output.push_back(*itr);
        }

        return output;
    }
};