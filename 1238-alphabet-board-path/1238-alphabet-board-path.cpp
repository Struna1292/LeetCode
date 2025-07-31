class Solution {
public:
    void moveToPosition(pair<int, int> start, pair<int, int> end, string& path) {
        // if we need to move to z
        if (end.first == 5 && end.second == 0) {
            // move to the proper j coordinate
            while (start.second != end.second) {
                // move right
                if (start.second < end.second) {
                    start.second++;
                    path.push_back('R');
                }
                else { // move left
                    start.second--;
                    path.push_back('L');
                }
            }
        }

        // move to the proper i coordinate
        while (start.first != end.first) {
            // move down
            if (start.first < end.first) {
                start.first++;
                path.push_back('D');
            }
            else { // move up
                start.first--;
                path.push_back('U');
            }
        }

        // move to the proper j coordinate
        while (start.second != end.second) {
            // move right
            if (start.second < end.second) {
                start.second++;
                path.push_back('R');
            }
            else { // move left
                start.second--;
                path.push_back('L');
            }
        }

        path.push_back('!');
    }

    string alphabetBoardPath(string target) {
        
        // map i,j position of every letter
        vector<pair<int, int>> alph = {
            {0,0}, {0,1}, {0,2}, {0,3}, {0,4},
            {1,0}, {1,1}, {1,2}, {1,3}, {1,4},
            {2,0}, {2,1}, {2,2}, {2,3}, {2,4},
            {3,0}, {3,1}, {3,2}, {3,3}, {3,4},
            {4,0}, {4,1}, {4,2}, {4,3}, {4,4},
            {5,0}
        };

        pair<int, int> prev = {0,0};
        string path = "";

        for (int i = 0; i < target.length(); i++) {
            moveToPosition(prev, alph[target[i]-'a'], path);
            prev = alph[target[i]-'a'];
        }

        return path;
    }
};