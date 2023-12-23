class Solution {
public:
    bool isPathCrossing(string path) {
        vector<pair<int,int>> coordinates = {{0,0}};

        int currX = 0;
        int currY = 0;

        for (char c : path)
        {
            if (c == 'N')
            {
                currY++;
            }
            else if (c == 'S')
            {
                currY--;
            }
            else if (c == 'E')
            {
                currX++;
            }
            else
            {
                currX--;
            }

            cout << currX << " " << currY << endl;

            for (int i = 0; i < coordinates.size(); i++)
            {
                if (currX == coordinates[i].first && currY == coordinates[i].second)
                {
                    return true;
                }
            }

            coordinates.push_back({currX, currY});
        }

        return false;
    }
};