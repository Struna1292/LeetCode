class Solution {
public:
    int minimumChairs(string s) {
        
        int counter = 0;
        int output = 0;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == 'E')
            {
                counter--;
                if (counter < output)
                {
                    output = counter;
                }
            }
            else
            {
                counter++;
            }
        }

        return output*(-1);
    }
};