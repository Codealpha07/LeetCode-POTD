class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int n1 = a.size();
        int n2 = b.size();
        
        // We strictly perform binary search on the smaller array 
        // to avoid index out of bounds in the larger array.
        if (n1 > n2) return findMedianSortedArrays(b, a);
        
        int low = 0, high = n1;
        int left_size = (n1 + n2 + 1) / 2;
        int n = n1 + n2;
        
        while (low <= high) {
            int mid1 = (low + high) / 2;
            int mid2 = left_size - mid1;
            
            // Assign boundary values, using infinities for edge cases
            int l1 = (mid1 > 0) ? a[mid1 - 1] : INT_MIN;
            int r1 = (mid1 < n1) ? a[mid1] : INT_MAX;
            
            int l2 = (mid2 > 0) ? b[mid2 - 1] : INT_MIN;
            int r2 = (mid2 < n2) ? b[mid2] : INT_MAX;
            
            // Check if we found the valid partition
            if (l1 <= r2 && l2 <= r1) {
                if (n % 2 == 1) {
                    // Total elements are odd, median is max of the left partitions
                    return (double)max(l1, l2);
                } else {
                    // Total elements are even, median is average of left max and right min
                    return (double)(max(l1, l2) + min(r1, r2)) / 2.0;
                }
            } 
            // We took too many elements from array 'a'
            else if (l1 > r2) {
                high = mid1 - 1;
            } 
            // We took too few elements from array 'a'
            else {
                low = mid1 + 1;
            }
        }
        
        return 0.0;
    }
};