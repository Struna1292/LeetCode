class Solution {
public:
    bool isNonCoprime(int a, int b) {

        if (gcd(a,b) != 1) {
            return true;
        }

        return false;
    }

    vector<int> replaceNonCoprimes(vector<int>& nums) {
        
        stack<int> st;

        for (int i = 0; i < nums.size(); i++) {
            while (!st.empty() && isNonCoprime(st.top(), nums[i])) {
                nums[i] = lcm(st.top(), nums[i]);
                st.pop();
            }
            st.push(nums[i]);            
        }

        vector<int> output(st.size(), 0);

        for (int i = output.size()-1; i >= 0; i--) {
            output[i] = st.top();
            st.pop();
        }   

        return output;
    }
};