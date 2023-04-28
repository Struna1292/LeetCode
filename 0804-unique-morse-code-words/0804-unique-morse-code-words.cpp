class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {

        vector<string> alphabet = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

        vector<string> storage;

        vector<string> coded;
        string curr;
        string empty;

        for (int i = 0; i < words.size(); i++)
        {
            for (int j = 0; j < words[i].length(); j++)
            {
                for (int k = 'a'; k <= 'z'; k++)
                {
                    if (k == words[i][j])
                    {
                        for (int l = 0; l < alphabet[k - 'a'].length(); l++)
                        {
                            curr.push_back(alphabet[k - 'a'][l]);
                        }
                        break;
                    }
                }
            }
            coded.push_back(curr);
            curr = empty;
        }

        class Ocurr {
        public:
            string morse;
            int times;
        };

        vector<Ocurr> occurrences;
        for (int i = 0; i < coded.size(); i++)
        {
            int counter = 0;
            for (int j = 0; j < occurrences.size(); j++)
            {
                if (occurrences[j].morse == coded[i])
                {
                    occurrences[j].times++;
                    break;
                }
                else
                {
                    counter++;
                }
            }
            if (counter == occurrences.size())
            {
                occurrences.push_back({coded[i], 1});
            }
        }

        return occurrences.size();

    }
};