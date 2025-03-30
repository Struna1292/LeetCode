class Solution {
public:
    vector<int> partitionLabels(string s) {
        // count the number of total occurrences
        map<char, int> total;

        for (char c : s)
        {
            total[c]++;
        }

        // when iterating from left the moment when the count of every letter that appears is equal to all occurrences count
        // that is the partition break point

        map<char, int> curr;

        int prevIndex = -1;
        vector<int> output;

        for (int i = 0; i < s.length(); i++)
        {
            curr[s[i]]++;

            bool match = true;
            for (auto itr = curr.begin(); itr != curr.end(); itr++)
            {
                if (itr->second != total[itr->first])
                {
                    match = false;
                    break;
                }
            }

            if (match)
            {
                output.push_back(i-prevIndex);
                prevIndex = i;
            }
        }

        return output;
    }
};