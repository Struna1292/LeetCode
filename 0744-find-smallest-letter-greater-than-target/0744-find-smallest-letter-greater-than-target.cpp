class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        sort(begin(letters),end(letters));
        for (int i = 0; i < letters.size(); i++)
        {
            if (letters[i] > target)
            {
                return letters[i];
            }
        }
        return letters[0];
    }
};