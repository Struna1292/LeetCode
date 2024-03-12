class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(begin(apple), end(apple));
        sort(begin(capacity), end(capacity), greater<int>());

        vector<bool> used(capacity.size(), false);

        int i = apple.size()-1;
        int j = 0;

        while (i >= 0)
        {
            used[j] = true;
            if (apple[i] <= capacity[j])
            {
                capacity[j] -= apple[i];
                i--;
                if (capacity[j] == 0)
                {
                    j++;
                }
            }
            else
            {
                apple[i] -= capacity[j];
                capacity[j] = 0;
                j++;
            }
        }

        if (used[j])
        {
            return j+1;
        }

        return j;
    }
};