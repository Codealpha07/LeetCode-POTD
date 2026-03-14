class Solution {
public:
    string getHappyString(int n, int k) {
        vector<string> store;
        generate(n, "a", store);
        generate(n, "b", store);
        generate(n, "c", store);
        if(store.size()<k) return "";
        return store[k-1];
    }
private:
    void generate(int n, string s, vector<string> &store){
        if(s.length()==n){store.push_back(s); return;}
        if(s.back()=='a'){
            generate(n, s+'b', store); generate(n, s+'c', store);
        }
        else if(s.back()=='b'){
            generate(n, s+'a', store); generate(n, s+'c', store);
        }
        else{
            generate(n, s+'a', store); generate(n, s+'b', store);
        }
    }
};