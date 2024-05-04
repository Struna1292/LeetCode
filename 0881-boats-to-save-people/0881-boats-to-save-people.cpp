class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        
        sort(begin(people), end(people));

        int i = 0;
        int j = people.size()-1;

        int boats = 0;

        while (i <= j)
        {
            if (people[j] == limit || ((people[j] + people[i]) > limit))
            {
                j--;
            }
            else if ((people[j] + people[i]) <= limit)
            {
                i++;
                j--;
            }
            else
            {
                i++;
            }
            boats++;
        }
        
        return boats;
    }
};