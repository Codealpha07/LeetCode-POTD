class Solution {
public:
    int trap(vector<int>& height) {
        // Amount of water that can sit at level i is determined by the maximumwall on left and on right that is : min(maxLeft[i], maxRight[i])-height[i]
        int n = height.size();
        vector<int> maxLeft(n), maxRight(n);
        maxLeft[0] = height[0], maxRight[n-1]=height[n-1];
        for(int i=1; i<n; i++) maxLeft[i] = max(maxLeft[i-1], height[i]);
        for(int i=n-2; i>=0; i--) maxRight[i] = max(maxRight[i+1], height[i]);
        int totalWater = 0;
        for(int i=0; i<n; i++){
            totalWater += min(maxLeft[i], maxRight[i])-height[i];
        }
        return totalWater;
    }
};