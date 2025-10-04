class Solution {
public:
    int maxArea(vector<int>& height) {
        int temp=0; int area = 0; 
        int l=0; int r=height.size()-1;
        while(l<r){
            temp = (r-l)*min(height[l], height[r]);
            area = max(area, temp);
            if(height[l]<height[r]) l++;
            else r--;
        }
        return area;
    }
};