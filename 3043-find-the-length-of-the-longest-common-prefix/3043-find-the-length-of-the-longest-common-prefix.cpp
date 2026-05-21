class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> prefixes;

        for (int i = 0; i < arr1.size(); i++) {
            do {
                prefixes.insert(arr1[i]);
                arr1[i] /= 10;
            }
            while (arr1[i] > 0);
        }

        unordered_set<int> checked;
        
        int currLongest = 0;
        for (int i = 0; i < arr2.size(); i++) {
            do {
                if (checked.contains(arr2[i])) {
                    break;
                }
                else {
                    checked.insert(arr2[i]);
                }

                if (prefixes.contains(arr2[i])) {
                    int currLength = to_string(arr2[i]).length();
                    currLongest = max(currLongest, currLength);
                    break;
                }
                arr2[i] /= 10;
            }
            while (arr2[i] > 0);
        }

        return currLongest;
    }
};