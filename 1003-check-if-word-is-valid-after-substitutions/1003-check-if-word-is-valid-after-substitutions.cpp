class Solution {
public:
    bool isValid(string s) {
        
        while(s.find("abc") != -1)
        {
            s.erase(s.find("abc"),3);
        }

        if (s == "")
        {
            return true;
        }
        return false;
    }
};