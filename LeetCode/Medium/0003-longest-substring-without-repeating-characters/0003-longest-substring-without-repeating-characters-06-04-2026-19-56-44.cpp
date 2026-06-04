class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0, bestLen = 0;
        unordered_map<char, int> freq;
        for(int r=0; r<s.length(); r++){
            freq[s[r]]++;
            while(freq[s[r]]!=1){
                freq[s[l++]]--;
            }
            bestLen = max(bestLen, r-l+1);
        }
        return bestLen;
    }
};