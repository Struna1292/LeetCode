class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        
        string output = paths[0][1];

        while (true)
        {
            bool found = false;
            for (int i = 0; i < paths.size(); i++)
            {
                if (output == paths[i][0])
                {
                    output = paths[i][1];
                    found = true;
                    break;
                }
            }

            if (!found)
            {
                break;
            }
        }

        return output;
    }
};