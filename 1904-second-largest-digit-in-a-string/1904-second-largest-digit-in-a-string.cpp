class Solution {
public:
    int secondHighest(string s) {
        
        char largest = '0'-1;
        char secondLargest = '0'-1;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                if (s[i] > largest)
                {
                    secondLargest = largest;
                    largest = s[i];
                }
                else if (s[i] > secondLargest && s[i] != largest)
                {
                    secondLargest = s[i];
                }
            }
        }

        return secondLargest - '0';
    }
};