class Robot {
public:
    struct Point {
        int x;
        int y;
        string direction;
        Point(int x, int y, string direction) {
            this->x = x;
            this->y = y;
            this->direction = direction;
        }
    };

    int index;
    vector<Point> line;
    bool moved;

    Robot(int width, int height) {
        this->moved = false;
        index = 0;

        Point point(0, 0, "South");
        line.push_back(point);

        point.direction = "East";
        for (int i = 0; i < width-1; i++) {
            point.x++;
            line.push_back(point);
        }

        point.direction = "North";
        for (int i = 0; i < height-1; i++) {
            point.y++;
            line.push_back(point);
        }

        point.direction = "West";
        for (int i = 0; i < width-1; i++) {
            point.x--;
            line.push_back(point);
        }

        point.direction = "South";
        for (int i = 0; i < height-2; i++) {
            point.y--;
            line.push_back(point);
        }
    }
    
    void step(int num) {
        index = (index + num) % line.size();

        if (!moved && num > 0) {
            moved = true;
        }
    }
    
    vector<int> getPos() {
        return {line[index].x, line[index].y};
    }
    
    string getDir() {
        if (index == 0 && !moved) {
            return "East";
        }

        return line[index].direction;
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */