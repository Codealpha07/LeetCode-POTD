class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        int n = temperatures.size();
        for(int i=0; i<n; i++){
            if(st.empty()) st.push(i);
            else if(temperatures[i]<=temperatures[st.top()]){
                st.push(i);
            }
            else{
                while(!st.empty() && temperatures[i]>temperatures[st.top()]){
                    int idx = st.top(); st.pop();
                    temperatures[idx] = i-idx;
                }
                st.push(i);
            }
        }
        while(!st.empty()){
            int idx = st.top(); st.pop();
            temperatures[idx] = 0;
        }
        return temperatures;
    }
};