class Solution {
public:
    bool hasAllCodes(string s, int k) {
        deque<char> que;
        unordered_set<string> us;

        string curr(k, '0');

        for (int i = 0; i < s.length(); i++) {
            que.push_back(s[i]);
            if (i >= k) {
                
                for (int j = 0; j < que.size(); j++) {
                    curr[j] = que[j];
                }

                us.insert(curr);
                que.pop_front();
            }
        }
        for (int j = 0; j < que.size(); j++) {
            curr[j] = que[j];
        }
        us.insert(curr);
        
        return us.size() == pow(2, k);
    }
};