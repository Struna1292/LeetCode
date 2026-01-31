class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        auto itr = upper_bound(letters.begin(), letters.end(), target);

        if (itr != letters.end()) {
            return *itr;
        }

        return letters[0];
    }
};