class Solution {
public:
    struct comparator {
        bool operator()(pair<int, int>& a, pair<int, int>& b) {
            if (a.first < b.first || (a.first == b.first && a.second > b.second)) {
                return true;
            }
            return false;
        }
    };

    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        // first sort capital in ascending order and profits in descending order
        // then iterate through all possible to buy 
        // contain only K in ordered multi map if its bigger and minimum then insert
        // after that pick the best profit and erase it from map and repeat previous operations until K is 0
    
        vector<pair<int, int>> costGain(profits.size()); // first = cost, second = gain
        for (int i = 0; i < profits.size(); i++) {
            costGain[i] = {capital[i], profits[i]};
        }

        sort(begin(costGain), end(costGain), comparator());

        multimap<int, int> mp; // key = gain, value = cost

        int currIndex = 0;
        int currCapital = w;

        while (k > 0) {
            // iterate through all affordable gains that we didnt iterate yet
            while (currIndex < costGain.size() && costGain[currIndex].first <= currCapital) {
                if (mp.size() < k) {
                    mp.insert({costGain[currIndex].second, costGain[currIndex].first});
                }
                else {
                    int lowestGain = mp.begin()->first;

                    if (lowestGain < costGain[currIndex].second) {
                        mp.insert({costGain[currIndex].second, costGain[currIndex].first});
                        mp.erase(mp.begin());
                    }
                }
                
                currIndex++;
            }

            if (mp.size() >= 1) {
                currCapital += mp.rbegin()->first; // collect biggest gain
                mp.erase(prev(mp.end())); // erase cant take reverse iterator

                k--;
            }
            else { // there is none to afford
                break;
            }
        }
        
        return currCapital;
    }
};