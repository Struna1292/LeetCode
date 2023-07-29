class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> output(num_people, 0);
        int i = 0;
        int j = 1;
        while (candies > 0)
        {
            if (candies >= j)
            {
                output[i] += j;
                candies -= j;
            }
            else
            {
                output[i] += candies;
                candies = 0;
            }
            j++;
            i++;
            if (i == num_people)
            {
                i = 0;
            }
        }

        return output;
    }
};