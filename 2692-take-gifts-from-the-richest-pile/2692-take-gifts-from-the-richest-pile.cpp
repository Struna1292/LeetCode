class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        
        multiset<int> st;

        for (int i = 0; i < gifts.size(); i++)
        {
            st.insert(gifts[i]);
        } 

        for (int i = 0; i < k; i++)
        {

            for (auto itr = st.rbegin(); itr != st.rend(); itr++)
            {
                int val = *(itr);
                st.insert(sqrt(val));
                st.erase(st.lower_bound(val));
                break;
            }
        }

        long long output = 0;

        for (auto itr = st.begin(); itr != st.end(); itr++)
        {
            output += *itr;
        }

        return output;
    }
};