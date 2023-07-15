class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        
        string curr = paths[0][1];
        int index = 0;
        while (true)
        {
            int counter = 0;
            for (int i = 1; i < paths.size(); i++)
            {
                if (paths[i][0] == curr && index != i)
                {
                    curr = paths[i][1];
                    index = i;
                    counter = 0;
                    break;
                }
                else
                {
                    counter++;
                }
            }
            
            if (counter+1 == paths.size())
            {
                break;
            }
        }


        return curr;
    }
};