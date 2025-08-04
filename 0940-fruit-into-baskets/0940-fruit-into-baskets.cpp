class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
        int mostFruits = 0;
        unordered_map<int, int> um; // key = type, value = count

        int typesCounter = 0;
        int fruitsCounter = 0;

        int windowStartIndex = 0;

        for (int i = 0; i < fruits.size(); i++) {
            if (um[fruits[i]] == 0) {
                if (typesCounter < 2) {
                    typesCounter++;
                }
                else { 
                    // remove from tail until we remove 1 type
                    do {
                        um[fruits[windowStartIndex]]--;
                        fruitsCounter--;
                        windowStartIndex++;
                    } while (um[fruits[windowStartIndex-1]] > 0);
                }
            }

            um[fruits[i]]++;
            fruitsCounter++;

            if (fruitsCounter > mostFruits) {
                mostFruits = fruitsCounter;
            }
        }

        return mostFruits;
    }
};