class Solution {
public:
    struct Point {
        int x = 0;
        int y = 0;
        Point(int f, int s) {
            x = f;
            y = s;
        }
        bool operator<(const Point& other) const {
            if (x == other.x) return y < other.y;
            return x < other.x;
        }
    };

    string directions = "NESW";

    int changeDirection(int currIndex, int instruction) {
        if (instruction == -1) {
            return (currIndex+1) % directions.length();
        }
        else if (instruction == -2) {
            currIndex--;
            if (currIndex < 0) {
                currIndex = directions.length()-1;
            }

            return currIndex;
        }   

        return currIndex;
    }

    void move(Point& point, int directionIndex) {

        char direction = directions[directionIndex];

        if (direction == 'N') { point.y++; }
        else if (direction == 'E') { point.x++; }
        else if (direction == 'S') { point.y--; }
        else if (direction == 'W') { point.x--; }
    }

    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<Point> obs; 
        for (int i = 0; i < obstacles.size(); i++) {
            obs.insert({obstacles[i][0], obstacles[i][1]});
        }
        
        Point point(0, 0);
        int directionIndex = 0;
        
        int output = 0;
        set<Point> visited;

        for (int i = 0; i < commands.size(); i++) {
            if (commands[i] < 0) {
                directionIndex = changeDirection(directionIndex, commands[i]);
            }
            else {

                for (int j = 0; j < commands[i]; j++) {
                    Point pointCopy = point;
                    move(pointCopy, directionIndex);

                    if (obs.contains(pointCopy)) {
                        break;
                    }

                    point = pointCopy;

                    if (visited.contains(point)) {
                        continue;
                    }

                    visited.insert(point);

                    if (output < (point.x * point.x) + (point.y * point.y)) {
                        output = (point.x * point.x) + (point.y * point.y);
                    }
                }

            }
        }

        return output;
    }
};