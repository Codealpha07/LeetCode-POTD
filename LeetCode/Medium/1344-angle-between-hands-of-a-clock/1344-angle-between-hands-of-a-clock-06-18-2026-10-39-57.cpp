class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hrRot = 30.0*(hour%12)+minutes/2.0;
        double minRot = 6.0*minutes;
        return min(abs(hrRot-minRot), 360-abs(hrRot-minRot));
    }
};