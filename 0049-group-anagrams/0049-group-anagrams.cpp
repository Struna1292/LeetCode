class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        struct Anagram {
            string sorted;
            vector<int> indexes;
        };

        vector<Anagram> anagrams;

        for (int i = 0; i < strs.size(); i++)
        {
            string check = strs[i];
            sort(begin(check), end(check));
            int counter = 0;
            for (int j = 0; j < anagrams.size(); j++)
            {
                if (anagrams[j].sorted == check)
                {
                    anagrams[j].indexes.push_back(i);
                    break;
                }
                counter++;
            }

            if (counter == anagrams.size())
            {
                anagrams.push_back({check, {i}});
            }
        }

        vector<vector<string>> output;

        for (int i = 0; i < anagrams.size(); i++)
        {
            vector<string> curr;
            for (int j = 0; j < anagrams[i].indexes.size(); j++)
            {
                curr.push_back(strs[anagrams[i].indexes[j]]);
            }
            output.push_back(curr);
        }

        return output;
    }
};