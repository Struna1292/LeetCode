class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        
        if (left == right)
        {
            return left;
        }
        
        string leftBin = bitset<32>(left).to_string();
        string rightBin = bitset<32>(right).to_string();

        int j = 31;

        int output = 0;

        for (int i = 0; i < 32; i++)
        {
            if (leftBin[i] == rightBin[i])
            {
                if (leftBin[i] == '1')
                {
                    output += pow(2, j);
                }
            }
            else
            {
                break;
            }
            j--;
        }

        return output;
    }
};