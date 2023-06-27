class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string,int> m;

        for (int i = 0; i < words1.size(); i++)
        {
            if (!m[words1[i]])
            {
                m[words1[i]]=1;
            }
            else
            {
                m[words1[i]] = -1;
            }
        }

        for (int i = 0; i < words2.size(); i++)
        {
            if (m[words2[i]] >= 1)
            {
                m[words2[i]]++;
            }
        }

        int counter = 0;

        for (auto it:m)
        {
            if (it.second == 2)
            {
                counter++;
            }
        }

        return counter;
    }
};