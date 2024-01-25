class Solution {
public:
    int minimumPushes(string word) {
        
        vector<int> letters(26, 0);

        for (int i = 0; i < word.length(); i++)
        {
            letters[word[i]-'a']++;
        }

        sort(begin(letters), end(letters), greater<int>());

        int counter = 0;
        int position = 1;

        int output = 0;

        for (int i = 0; i < 26; i++)
        {
            if (letters[i] > 0)
            {            
                output += (letters[i] * position);
                counter++;

                if (counter == 8)
                {
                    position++;
                    counter = 0;
                }
            }
        }

        return output;
    }
};