class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        
        int output = 0;

        int prevLasers = 0;

        for (int i = 0; i < bank.size(); i++)
        {
            int currLasers = 0;
            for (int j = 0; j < bank[i].length(); j++)
            {
                if (bank[i][j] == '1')
                {
                    currLasers++;
                }
            }

            if (currLasers > 0)
            {
                output += (prevLasers * currLasers);
                prevLasers = currLasers;
            }
        }

        return output;
    }
};