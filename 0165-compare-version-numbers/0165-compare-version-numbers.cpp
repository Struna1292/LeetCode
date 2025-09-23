class Solution {
public:
    vector<int> convertToVector(string& version) {
        vector<int> nums;
        string curr = "";
        for (int i = 0; i < version.length(); i++) {
            if (version[i] == '.') {
                nums.push_back(stoi(curr));
                curr = "";
            }
            else {
                curr.push_back(version[i]);
            }
        }
        nums.push_back(stoi(curr));

        return nums;        
    }

    void fixSizes(vector<int>& nums1, vector<int>& nums2) {
        while (nums1.size() < nums2.size()) {
            nums1.push_back(0);
        }

        while (nums2.size() < nums1.size()) {
            nums2.push_back(0);
        }        
    }

    int compareVersion(string version1, string version2) {
        
        vector<int> nums1 = convertToVector(version1);
        vector<int> nums2 = convertToVector(version2);

        fixSizes(nums1, nums2);

        for (int i = 0; i < nums1.size(); i++) {
            if (nums1[i] > nums2[i]) {
                return 1;
            }
            else if (nums1[i] < nums2[i]) {
                return -1;
            }
        }

        return 0;
    }
};