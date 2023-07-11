class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        
        vector<int> freq(words.size(), 0);

        for (int i = 0; i < words.size(); i++)
        {
            int counter = 1;
            char c = words[i][0];
            for (int j = 1; j < words[i].length(); j++)
            {
                if (words[i][j] < c)
                {
                    c = words[i][j];
                    counter = 1;
                }
                else if (words[i][j] == c)
                {
                    counter++;
                }
            }

            freq[i] = counter;
        }

        sort(begin(freq), end(freq));

        vector<int> output;
        for (int i = 0; i < queries.size(); i++)
        {
            int counter = 1;
            char c = queries[i][0];
            for (int j = 1; j < queries[i].length(); j++)
            {
                if (queries[i][j] < c)
                {
                    c = queries[i][j];
                    counter = 1;
                }
                else if (queries[i][j] == c)
                {
                    counter++;
                }
            }

            int index = lower_bound(begin(freq), end(freq), counter+1) - freq.begin();
            int num = freq.size() - index;

            output.push_back(num);
        }

        return output;
    }
};