class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int l=0, r=letters.size();
        int ans = 0;
        while(l<r){
            int mid = (l+r)/2;
            if(letters[mid]>target) ans=mid, r=mid;
            else l=mid+1;
        }
        return letters[ans];
    }
};