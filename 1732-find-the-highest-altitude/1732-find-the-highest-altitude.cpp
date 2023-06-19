class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int highest = 0;
        int curr = 0;
        for (int i = 0; i < gain.size(); i++)
        {
            curr += gain[i];
            if (curr > highest)
            {
                highest = curr;
            }
        }
        return highest;
    }
};