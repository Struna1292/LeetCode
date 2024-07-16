class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        
        int output = 0;

        for (int i = 1; i < colors.size()-1; i++)
        {
            if (colors[i-1] == colors[i+1] && colors[i] != colors[i-1])
            {
                output++;
            }
        }

        if (colors[colors.size()-2] == colors[0] && colors[colors.size()-1] != colors[0])
        {
            output++;
        }

        if (colors[colors.size()-1] == colors[1] && colors[1] != colors[0])
        {
            output++;
        }

        return output;
    }
};