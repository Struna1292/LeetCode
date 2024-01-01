class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(begin(g), end(g));
        sort(begin(s), end(s));

        int output = 0;

        int j = g.size()-1;

        for (int i = s.size()-1; i >= 0; i--)
        {   
            
            if (j < 0)
            {
                break;
            }

            for (j; j >= 0; j--)
            {
                if (s[i] >= g[j]) 
                {
                    output++;
                    j--;
                    break;
                }
            }
        }

        return output;
    }
};