class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {

        map<string, int> mp;

        for (int i = 0; i < word.length(); i += k)
        {
            int border = i+k;

            if (border <= word.length())
            {
                string curr;
                for (int j = i; j < border; j++)
                {   
                    curr.push_back(word[j]);
                }

                mp[curr]++;
            }
        }

        map<string, int>::iterator itr;

        int total = 0;
        int mostFrequent = 0;

        for (itr = mp.begin(); itr != mp.end(); itr++)
        {
            total += itr->second;

            if (itr->second > mostFrequent)
            {
                mostFrequent = itr->second;
            }
        }
        

        return total - mostFrequent;
    }
};