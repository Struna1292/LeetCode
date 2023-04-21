class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int,string>> symbols = {{1,"I"}, {4, "IV"}, {5, "V"}, {9, "IX"}, {10, "X"}, {40, "XL"}, {50, "L"}, {90, "XC"}, {100, "C"}, {400, "CD"}, {500, "D"}, {900, "CM"}, {1000, "M"}};
        string output;
        int i = symbols.size() - 1;
        while (num > 0)
        {
            if (num >= symbols[i].first)
            {
                num -= symbols[i].first;
                for (int j = 0; j < symbols[i].second.length(); j++)
                {
                    output.push_back(symbols[i].second[j]);
                }
            }
            else
            {
                i--;
            }
        }
        return output;
    }
};