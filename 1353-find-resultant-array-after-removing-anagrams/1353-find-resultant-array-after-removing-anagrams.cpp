class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {

        string prev = words[0];
        sort(begin(prev), end(prev));
        vector<bool> deleted(words.size(), false);

        for (int i = 1; i < words.size(); i++) {
            string curr = words[i];
            sort(begin(curr), end(curr));

            if (prev == curr) {
                deleted[i] = true;
            }
            else {
                prev = curr;
            }
        }

        vector<string> output;

        for (int i = 0; i < words.size(); i++) {
            if (!deleted[i]) output.push_back(words[i]);
        }

        return output;
    }
};