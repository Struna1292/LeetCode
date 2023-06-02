class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        
        vector<int> p (m, 0);

        for (int i = 0; i < m; i++)
        {
            p[i] = i+1;
        }

        vector<int> answer;
        
        for (int i = 0; i < queries.size(); i++)
        {
            for (int j = 0; j < p.size(); j++)
            {
                if (queries[i] == p[j])
                {
                    answer.push_back(j);
                    while (j > 0)
                    {
                        swap(p[j], p[j-1]);
                        j--;
                    }
                    break;
                }
            }
        }

        return answer;
    }
};