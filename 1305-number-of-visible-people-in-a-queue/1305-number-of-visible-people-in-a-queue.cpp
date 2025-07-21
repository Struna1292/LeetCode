class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {

        // iterate from right and keep track of people in stack
        // when current height is smaller than first on stack then we can see only this guy
        // when current height is greater then we pop and count all the people we can see
        // we can pop them because current will cover them from the rest

        stack<int> st;
        vector<int> output(heights.size(), 0);

        for (int i = heights.size()-1; i >= 0; i--) {
            if (!st.empty()) {

                if (st.top() > heights[i]) {
                    output[i] = 1; // current is smaller and can see only 1
                }
                else {
                    int smallerCounter = 0;

                    while (!st.empty() && st.top() < heights[i]) { // pop all smaller in stack and count them
                        st.pop();
                        smallerCounter++;
                    }

                    if (!st.empty()) { // check if there is still 1 more higher
                        smallerCounter++;
                    }

                    output[i] = smallerCounter;
                }
            }
            st.push(heights[i]);
        }

        return output;
    }
};