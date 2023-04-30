class Solution {
public:
    int findDelayedArrivalTime(int arrivalTime, int delayedTime) {
        return arrivalTime + delayedTime > 23 ? arrivalTime + delayedTime - 24 : arrivalTime + delayedTime;
    }
};