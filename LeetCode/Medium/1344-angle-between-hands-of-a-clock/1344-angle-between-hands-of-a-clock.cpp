class Solution {
public:
    double angleClock(int hour, int minutes) {
        double m = minutes * 6 % 360, h = hour * 30 + (double)minutes / 2;
        double gap = abs(h - m);
        return min(gap, 360 - gap);
    }
};