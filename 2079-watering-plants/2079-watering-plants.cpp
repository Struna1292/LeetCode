class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {

        int currWater = capacity;
        int steps = 0;

        for (int i = 0; i < plants.size(); i++)
        {
            if (currWater >= plants[i])
            {
                currWater -= plants[i];
                steps++;
            }
            else
            {
                steps += (i*2)+1;
                currWater = capacity - plants[i];
            }
        }

        return steps;
    }
};