class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        vector<int> output;

        for (int i = 0; i < nums1.size(); i++)
        {
            for (int j = 0; j < nums2.size(); j++)
            {
                if (nums1[i] == nums2[j])
                {
                    int counter = j+1;
                    for (int k = j + 1; k < nums2.size(); k++)
                    {
                        if (nums2[k] > nums2[j])
                        {
                            output.push_back(nums2[k]);
                            break;
                        }
                        else
                        {
                            counter++;
                        }
                    }
                    if (counter == nums2.size())
                    {
                        output.push_back(-1);
                    }
                }
            }
        }

        return output;
    }
};