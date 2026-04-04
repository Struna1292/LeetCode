class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        if (rows == 1) return encodedText;

        int n = encodedText.size();
        int cols = n / rows;

        string result;

        for (int start = 0; start < cols; start++) {
            int r = 0, c = start;

            while (r < rows && c < cols) {
                result.push_back(encodedText[r * cols + c]);
                r++;
                c++;
            }
        }
        
        while (!result.empty() && result.back() == ' ') {
            result.pop_back();
        }

        return result;
    }
};