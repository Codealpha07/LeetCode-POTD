class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.length();
        int best = 1;
        unordered_map<int, int> freq;
        int l=0, r=0;
        while(r<n){
            if(freq[s[r]]==2){
                best = max(best, r-l);
                while(freq[s[r]]!=1) freq[s[l++]]--;
            }
            freq[s[r]]++;
            r++;
        }
        best = max(best, r-l);
        return best;
    }
};