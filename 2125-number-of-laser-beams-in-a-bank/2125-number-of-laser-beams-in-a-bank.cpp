class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int counter1 = 0;
        int counter2 = 0;
        int lasers = 0;
        for (int i = 0; i < bank.size(); i++)
        {
            for (int j = 0; j < bank[i].length(); j++)
            {
                if (bank[i][j] == '1')
                {
                    counter1++;
                }
            }
            if (counter1 != 0)
            {
                lasers += counter1 * counter2;
                counter2 = counter1;
                counter1 = 0;
            }
        }
        return lasers;
    }
};