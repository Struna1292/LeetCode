class Solution {
public:
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {

        sort(begin(nums1), end(nums1));
        sort(begin(nums2), end(nums2));
        
        for (int avoid1 = 0; avoid1 < nums1.size()-1; avoid1++)
        {
            for (int avoid2 = avoid1+1; avoid2 < nums1.size(); avoid2++)
            {

                int j = 0;

                int difference = 0;

                bool first = true;

                for (int i = 0; i < nums1.size(); i++)
                {
                    if (i != avoid1 && i != avoid2)
                    {
                        if (first)
                        {
                            difference = nums2[j] - nums1[i];
                            j++;
                            first = false;
                        }
                        else
                        {
                            if (difference != (nums2[j] - nums1[i]))
                            {
                                break;
                            }
                            else
                            {
                                j++;
                            }
                        }
                    }
                }

                if (j == nums2.size())
                {
                    return difference;
                }

            }
        }


        return -1;
    }
};