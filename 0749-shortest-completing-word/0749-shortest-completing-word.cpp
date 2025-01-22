class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        
        int alph[26] = { 0 };

        for (char c : licensePlate)
        {
            if (c >= 'A' && c <= 'Z')
            {
                c += 32;
            }
            if (c >= 'a' && c <= 'z')
            {
                alph[c-'a']++;
            }
        }

        int shortestIndex = -1;

        for (int i = 0; i < words.size(); i++)
        {
            int curr[26] = { 0 };

            for (char c : words[i])
            {
                curr[c-'a']++;
            }

            bool match = true;
            for (int j = 0; j < 26; j++)
            {
                if (curr[j] < alph[j])
                {
                    match = false;
                    break;
                }
            }

            if (match && (shortestIndex == -1 || words[i].length() < words[shortestIndex].length()))
            {
                shortestIndex = i;
            }
        }

        return words[shortestIndex];
    }
};