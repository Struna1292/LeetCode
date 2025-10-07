class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        
        set<int> st; // que of dry indexes
        unordered_map<int, int> um; // lake id, last occurrence index

        vector<int> output(rains.size(), -1);

        for (int i = 0; i < rains.size(); i++) {

            if (rains[i] == 0) {
                st.insert(i);
                continue;
            }

            if (um.find(rains[i]) == um.end()) {
                um[rains[i]] = i;
                continue;
            }
            
            auto itr = st.upper_bound(um[rains[i]]);

            if (itr == st.end()) {
                return {};
            }

            um[rains[i]] = i;
            output[*itr] = rains[i];
            st.erase(itr);
        }

        for (auto itr = st.begin(); itr != st.end(); itr++) {
            output[*itr] = 1;
        }

        return output;
    }
};