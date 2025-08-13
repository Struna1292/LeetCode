class Solution {
public:
    struct comparator {
        bool operator()(vector<int>& a, vector<int>& b) {
            if (a[0] < b[0] || (a[0] == b[0] && a[1] > b[1])) {
                return true;
            }

            return false;
        }
    };

    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(begin(people), end(people), comparator());
        vector<vector<int>> output(people.size(), {-1, -1});

        set<int> indexes;

        for (int i = 0; i < people.size(); i++) {

            int index = people[i][1];
            int prev = 0;
            
            while (true) {
                int previousCount = distance(indexes.begin(), indexes.lower_bound(index+1)) - prev;

                if (previousCount == 0) {
                    break;
                }

                index += previousCount;
                prev += previousCount;
            }

            output[index] = people[i];
            indexes.insert(index);
        }

        return output;
    }
};