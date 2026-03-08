class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        
        set<int> st;
        for (string s : nums) {
            int curr = stoi(s, nullptr, 2);
            st.insert(curr);
        }

        int length = nums[0].length();
        int maxNumber = 0;
        for (int i = length; i > 0; i--) {
            maxNumber <<= 1;
            maxNumber |= 1;
        }

        while (maxNumber >= 0) {

            if (!st.contains(maxNumber)) {
                string s = bitset<64>(maxNumber).to_string();
                string output(length, '0');

                for (int j = 0; j < length; j++) {
                    output[j] = s[s.length()-length+j];
                }

                return output;
            }

            maxNumber--;
        }

        return "";
    }
};