class Solution {
public:
    double angleClock(int hour, int minutes) {

        double minutesAngle = minutes * 6;
        double hourAngle = (hour + ((double)minutes / 60.0)) * 30;

        double absAngle = abs(minutesAngle - hourAngle);

        return min(absAngle, 360 - absAngle);
    }
};