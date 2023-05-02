class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> indexesPrev = {-1};
        for (int i = 0; i < words.size(); i++)
        {
            vector<int> indexesCurr;
            for (int j = 0; j < words[i].size(); j++)
            {
                for (int k = 0; k < order.size(); k++)
                {
                    if (order[k] == words[i][j])
                    {
                        indexesCurr.push_back(k);
                        break;
                    }
                }
            }
            
            int l = 0;

            for (int k = 0; k < indexesCurr.size(); k++)
            {
                if (indexesCurr[k] < indexesPrev[l])
                {
                    return false;
                }
                else if (indexesCurr[k] > indexesPrev[l])
                {
                    break;
                }
                if (l+1 != indexesPrev.size())
                {
                    l++;
                }
                else
                {
                    break;
                }
            }

            if (indexesCurr.size() < indexesPrev.size() && l == indexesCurr.size())
            {
                return false;
            }

            indexesPrev = indexesCurr;
        }

        return true;
    }
};