class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        
        for (int i = 0; i < words.size(); i++) {

            int left = (startIndex - i + words.size()) % words.size();
            int right = (startIndex + i) % words.size();

            if (words[left] == target || words[right] == target) {
                return i;
            }
        }

        return -1;
    }
};