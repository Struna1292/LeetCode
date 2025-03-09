class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        
        // iterate through to find first k alternating colors
        // then check next color if it's alternating count++
        // else start searching from this position
        
        int currCounter = 0;
        int output = 0;

        for (int i = 1; i < colors.size()+k-1; i++)
        {
            if (colors[(i-1)%colors.size()] != colors[i%colors.size()])
            {
                if (currCounter == k-1)
                {
                    output++;
                }
                else
                {
                    currCounter++;
                    if (currCounter == k-1)
                    {
                        output++;
                    }
                }
            }
            else
            {
                currCounter = 0;
            }
        }

        return output;
    }
};