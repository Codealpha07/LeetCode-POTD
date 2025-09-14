class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> words(wordlist.begin(), wordlist.end());
        unordered_map<string, string> cap, vow;

        for (const string& w : wordlist) {
            string lower = toLower(w);
            if (!cap.count(lower)) cap[lower] = w;
            string devow = devowel(lower);
            if (!vow.count(devow)) vow[devow] = w;
        }

        vector<string> res;
        for (const string& q : queries) {
            if (words.count(q)) {
                res.push_back(q);
                continue;
            }
            string lower = toLower(q);
            if (cap.count(lower)) {
                res.push_back(cap[lower]);
                continue;
            }
            string devow = devowel(lower);
            if (vow.count(devow)) {
                res.push_back(vow[devow]);
                continue;
            }
            res.push_back("");
        }
        return res;
    }

private:
    string toLower(const string& s) {
        string res = s;
        for (char& c : res) c = tolower(c);
        return res;
    }
    string devowel(const string& s) {
        string res = s;
        for (char& c : res)
            if (isVowel(c)) c = '*';
        return res;
    }
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};