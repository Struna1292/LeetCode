class Solution {
public:
    struct point {
        int i;
        int j;
        point(int indexI, int indexJ) {
            i = indexI;
            j = indexJ;
        }
    };

    point partition(point left, point right, vector<vector<int>>& nums, bool& increasing) {

        point pivotIndex = right;
        point index = left;

        for (point curr = left; curr.i < right.i && curr.j < right.j; curr.i++, curr.j++) {
            if (increasing) {
                if (nums[curr.i][curr.j] < nums[pivotIndex.i][pivotIndex.j]) {
                    swap(nums[curr.i][curr.j], nums[index.i][index.j]);
                    index.i++;
                    index.j++;
                }
            }
            else {
                if (nums[curr.i][curr.j] > nums[pivotIndex.i][pivotIndex.j]) {
                    swap(nums[curr.i][curr.j], nums[index.i][index.j]);
                    index.i++;
                    index.j++;
                }
            }
        }

        swap(nums[pivotIndex.i][pivotIndex.j], nums[index.i][index.j]);

        return index;
    }

    void quickSort(vector<vector<int>>& nums, point left, point right, bool& increasing) {
        if (left.j >= right.j) {
            return;
        }

        point pivot = partition(left, right, nums, increasing);

        quickSort(nums, left, {pivot.i-1, pivot.j-1}, increasing);

        quickSort(nums, {pivot.i+1, pivot.j+1}, right, increasing);
    }

    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        bool increasing = false;
        for (int i = 0; i < grid.size(); i++) {
            quickSort(grid, point(i, 0), point(grid.size()-1, grid.size()-1-i), increasing);
        }

        increasing = true;
        for (int i = 1; i < grid[0].size(); i++) {
            quickSort(grid, point(0, i), point(grid.size()-1-i, grid.size()-1), increasing);
        }

        return grid;
    }
};