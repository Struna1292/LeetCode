class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        
        vector<int> hash(A.size()+1, 0);

        vector<int> output;

        int counter = 0;

        for (int i = 0; i < A.size(); i++)
        {
            hash[A[i]]++;
            hash[B[i]]++;

            if (hash[A[i]] == 2)
            {
                counter++;
            }
            if (hash[B[i]] == 2 && A[i] != B[i])
            {
                counter++;
            }

            output.push_back(counter);
        }

        return output;
    }
};