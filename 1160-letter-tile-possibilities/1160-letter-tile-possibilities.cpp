class Solution {
public:
    void helper(string& tiles, vector<bool>& used, set<string>& st, string curr)
    {
        for (int i = 0; i < tiles.length(); i++)
        {
            if (!used[i])
            {
                used[i] = true;
                string c = curr;
                c.push_back(tiles[i]);
                st.insert(c);
                helper(tiles, used, st, c);
                used[i] = false;
            }
        }
    }

    int numTilePossibilities(string tiles) {
        set<string> st;

        vector<bool> used(tiles.length(), false);

        helper(tiles, used, st, "");

        return st.size();
    }
};