class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();

        vector<int> output(n, 0);
        unordered_set<int> visited;

        int counter = 0;

        for (int i = n-1; i >= 0; i--) {
            output[i] = n-counter;

            if (!visited.contains(A[i])) {
                visited.insert(A[i]);
                counter++;
            }

            if (!visited.contains(B[i])) {
                visited.insert(B[i]);
                counter++;
            }
        }

        return output;
    }
};