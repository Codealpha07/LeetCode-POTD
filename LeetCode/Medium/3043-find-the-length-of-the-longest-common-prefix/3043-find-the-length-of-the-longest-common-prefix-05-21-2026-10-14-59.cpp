class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        set<string> store;
        for(int x:arr1) fun(store, x);
        int ans = 0;
        for(int x:arr2){
            string s = to_string(x);
            string pre="";
            for(char c:s){
                pre+=c;
                if(store.find(pre)!=store.end()){
                    int l = pre.length();
                    ans = max(ans, l);
                }
            }
        }
        return ans;
    }
private:
    void fun(set<string> &store, int x){
        string s = to_string(x);
        string pre = "";
        for(char c:s) {pre+=c; store.insert(pre);}
    }
};