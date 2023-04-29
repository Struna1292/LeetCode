class Solution {
public:
    string sortString(string s) {

        sort(begin(s), end(s));
        
        class Occurr {
            public:
                char letter;
                int times;
        };

        vector<Occurr> occurrences;
        for (int i = 0; i < s.length(); i++)
        {
            int counter = 0;
            for (int j = 0; j < occurrences.size(); j++)
            {
                if (s[i] == occurrences[j].letter)
                {
                    occurrences[j].times++;
                }
                else
                {
                    counter++;
                }
            }
            if (counter == occurrences.size())
            {
                occurrences.push_back({s[i], 1});
            }
        }

        string output;

        while (output.length() != s.length())
        {
            for (int i = 0; i < occurrences.size(); i++)
            {
                if (occurrences[i].times > 0)
                {
                    output.push_back(occurrences[i].letter);
                    occurrences[i].times--;
                }
            }

            for (int i = occurrences.size()-1; i >= 0; i--)
            {
                if (occurrences[i].times > 0)
                {
                    output.push_back(occurrences[i].letter);
                    occurrences[i].times--;
                }
            }
        }
    
        return output;
    }
};