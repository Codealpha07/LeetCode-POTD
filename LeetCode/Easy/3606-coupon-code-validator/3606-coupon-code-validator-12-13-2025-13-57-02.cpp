class Solution {
public:
    set<string> validBusinessLines = {"electronics", "grocery", "pharmacy", "restaurant"};

    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<pair<int, string>> paired;
        int n = code.size();
        for (int i = 0; i < n; i++) {
            if (isActive[i] && checkCode(code[i]) && checkBusinessLine(businessLine[i])) {
                if (businessLine[i][0] == 'e') paired.push_back({0, code[i]});
                else if (businessLine[i][0] == 'g') paired.push_back({1, code[i]});
                else if (businessLine[i][0] == 'p') paired.push_back({2, code[i]});
                else paired.push_back({3, code[i]});
            }
        }

        sort(paired.begin(), paired.end());
        vector<string> ans;
        for (const auto& p : paired) ans.push_back(p.second);
        return ans;
    }

private:
    bool checkCode(const string& s) {
        if (s.empty()) return false;
        for (char c : s) {
            if ((!isalnum(static_cast<unsigned char>(c)) && c != '_'))
                return false;
        }
        return true;
    }

    bool checkBusinessLine(const string& s) {
        return validBusinessLines.count(s) > 0;
    }
};
