class Solution {
public:
    string removeOccurrences(string s, string part) {
        
        while (true)
        {
            int index = s.find(part);
            if (index == -1)
            {
                break;
            }
            else
            {
                s.erase(index, part.length());
            }
        }

        return s;
    }
};