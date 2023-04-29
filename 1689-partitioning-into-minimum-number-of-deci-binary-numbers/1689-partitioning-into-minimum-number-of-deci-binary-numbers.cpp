class Solution {
public:
    int minPartitions(string n) {
        char biggest = '0';
        for (int i = 0; i < n.length(); i++)
        {
            if (n[i] == '9')
            {
                return 9;
            }
            else if (n[i] > biggest)
            {
                biggest = n[i];
            }
        }
        return biggest - '0';
    }
};