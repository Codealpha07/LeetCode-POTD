class Solution {
public: 
    double separateSquares(vector<vector<int>>& squares) {
        double totalArea = 0, l = 2*1e9, h = 0;
        for (auto& s : squares) {
            double y = s[1], side = s[2];
            totalArea += side*side;
            l=min(l,y);
            h=max(h,y+side);
        }
        double targetArea = totalArea / 2.0;
        for(int i=0; i<1000; i++){
            double mid = l+(h-l)/2.0;
            double currArea = 0;
            for (auto& s : squares) {
                double y = s[1];
                double side = s[2];
                double h_below = max(0.0, min(side, mid - y));
                currArea += h_below*side;
            }

            if (currArea < targetArea) l = mid;
            else  h = mid;
        }
        return h;
    }
};