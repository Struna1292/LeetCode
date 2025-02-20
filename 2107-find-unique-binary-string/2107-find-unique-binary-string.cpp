class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        
        // generate maximum possible number to given length by setting all 1
        int length = nums[0].length();
        int maxNumber = 0;

        for (int i = length; i > 0; i--)
        {
            maxNumber <<= 1;
            maxNumber |= 1;
        }

        // convert given binary representations to int and insert to set
        set<int> st;

        for (string s : nums)
        {
            int curr = stoi(s, nullptr, 2);
            st.insert(curr);
        }

        // iterate down from maximum number and check if current number exists in set

        for (int i = maxNumber; i >= 0; i--)
        {
            if (!st.contains(i))
            {
                string s = bitset<64>(i).to_string();

                string output(length, '0');

                for (int j = 0; j < length; j++)
                {
                    output[j] = s[s.length()-length+j];
                }

                return output;
            }
        }

        return "";
    }
};