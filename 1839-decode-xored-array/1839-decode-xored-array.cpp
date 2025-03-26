class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        
        vector<int> decoded = {first};

        for (int i = 1; i <= encoded.size(); i++)
        {
            decoded.push_back((decoded[i-1]^encoded[i-1]));
        }

        return decoded;
    }
};