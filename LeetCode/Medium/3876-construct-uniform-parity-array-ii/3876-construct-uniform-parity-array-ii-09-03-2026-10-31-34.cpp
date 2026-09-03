class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        bool check1=true, check2=true;
        int minOdd=INT_MAX;
        for(int i=0; i<n; i++){
            if(nums1[i]%2==0) continue;
            else{
                minOdd=min(minOdd, nums1[i]);
            }
        }
        if(minOdd==INT_MAX) return true;
        for(int i=0; i<n; i++){
            if(nums1[i]%2==0) continue;
            else if(nums1[i]<=minOdd) check1=false;
        }
        for(int i=0; i<n; i++){
            if(nums1[i]%2==1) continue;
            else if(nums1[i]<=minOdd) check2=false;
        }
        return check1||check2;
    }
};