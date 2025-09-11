class Solution {
public:
    string sortVowels(string s) {
        int n = s.size();
        unordered_map<char, int> freq;
        vector<char> vowels = {'A', 'E','I','O','U', 'a','e','i','o','u'};
        vector<int> pos;
        for(int i=0; i<n; i++){
            if(find(vowels.begin(), vowels.end(), s[i])!=vowels.end()){
                pos.push_back(i);
                freq[s[i]]++;
            }
        }
        for(int i:pos){
            for(int j=0; j<10; j++){
                if(freq[vowels[j]]>0){
                    s[i] = vowels[j];
                    freq[vowels[j]]--;
                    break;
                }
            }
        }
        return s;
    }
};