class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> um;

        for (int i = 0; i < text.length(); i++) {
            um[text[i]]++;
        }
        um['l'] /= 2;
        um['o'] /= 2;

        string s = "balon";

        int currMin = um['b'];

        for (int i = 1; i < s.length(); i++) {
            currMin = min(currMin, um[s[i]]);
        }

        return currMin;
    }
};