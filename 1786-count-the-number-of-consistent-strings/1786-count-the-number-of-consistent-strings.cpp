class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        
        int alph[26] = { 0 };

        for (char c : allowed)
        {
            alph[c - 'a']++;
        }

        int counter = 0;

        for (string word : words)
        {
            bool match = true;
            for (char c : word)
            {
                if (alph[c-'a'] == 0)
                {
                    match = false;
                    break;
                }
            }

            if (match)
            {
                counter++;
            }
        }

        return counter;
    }
};