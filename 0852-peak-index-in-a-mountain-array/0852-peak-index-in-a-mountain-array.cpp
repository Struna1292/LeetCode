class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 0;
        int right = arr.size();

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (mid-1 < 0)
            {
                mid++;
            }
            else if (mid+1 == arr.size())
            {
                mid--;
            }
            if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1])
            {
                return mid;
            }
            if (arr[mid] < arr[mid+1])
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return -1;
    }
};