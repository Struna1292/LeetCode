class Solution {
public:
    bool isVowel(char c)
    {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
        {
            return true;
        }
        return false;
    }

    string sortVowels(string s) {
        vector<char> vowels;
        vector<int> indexes;

        for (int i = 0; i < s.length(); i++)
        {
            if (isVowel(s[i]))
            {
                vowels.push_back(s[i]);
                indexes.push_back(i);
            }
        }

        sort(begin(vowels), end(vowels));

        for (int i = 0; i < indexes.size();i++)
        {
            s[indexes[i]] = vowels[i];
        }

        return s;
    }   
};