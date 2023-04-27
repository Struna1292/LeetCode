class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {

        if (s1.length() != s2.length())
        {
            return false;
        }
        else if (s1 == s2)
        {
            return true;
        }

        int counter = 0;
        vector<int> check1;
        vector<int> check2;
        for (int i = 0; i < s1.length(); i++)
        {
            if (s1[i] != s2[i])
            {
                check1.push_back(s1[i]);
                check2.push_back(s2[i]);
                counter++;
            }
        }

        if (counter == 2)
        {
            sort(begin(check1), end(check1));
            sort(begin(check2), end(check2));
            if (check1 == check2)
            {
                return true;
            }
        }
        return false;
    }
};