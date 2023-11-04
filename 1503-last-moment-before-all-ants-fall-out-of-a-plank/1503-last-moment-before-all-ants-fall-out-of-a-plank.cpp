class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {

        sort(begin(left), end(left));
        sort(begin(right), end(right));

        if (left.size() == 0)
        {
            return n - right[0];
        }
        else if (right.size() == 0)
        {
            return left[left.size()-1];
        }

        if (n - right[0] > left[left.size()-1])
        {
            return n - right[0];
        }

        return left[left.size()-1];
    }
};