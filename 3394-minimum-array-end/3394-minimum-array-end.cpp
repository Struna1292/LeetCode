class Solution {
public:
    long long minEnd(int n, int x) {
        // every 1 in binary representation in x is immutable
        // we need to check indexes where are 0 in x
        // then we take our number of combinations n
        // we change them to binary representation
        // and to 0 indexes we collected earlier we change them to our binary representation of current number from n

        string xRep = bitset<64>(x).to_string();

        string lastN = bitset<64>(n-1).to_string(); 

        int j = xRep.length()-1;

        for (int i = lastN.length()-1; i >= 0; i--)
        {
            if (j < 0)
            {
                break;
            }
            while (j > 0 && xRep[j] == '1')
            {
                j--;
            }

            if (xRep[j] == '0' && lastN[i] == '1')
            {
                xRep[j] = '1';
            }
            j--;
        }

        bitset<64> bitset(xRep);

        long long output = static_cast<int64_t>(bitset.to_ullong());

        return output;
    }
};