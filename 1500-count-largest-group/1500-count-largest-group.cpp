class Solution {
public:
    int countLargestGroup(int n) {
        
        map<int,int> mp; // key is sum of digits, value is count 

        for (int i = n; i >= 1; i--)
        {
            string s = to_string(i);
            int currSum = 0;

            for (char c : s)
            {
                currSum += c-'0';
            }

            mp[currSum]++;
        }

        int counter = 0;
        int currBiggest = 0;

        for (auto itr = mp.begin(); itr != mp.end(); itr++)
        {
            if (itr->second > currBiggest)
            {
                counter = 1;
                currBiggest = itr->second;
            }
            else if (itr->second == currBiggest)
            {
                counter++;
            }
        }

        return counter;
    }
};