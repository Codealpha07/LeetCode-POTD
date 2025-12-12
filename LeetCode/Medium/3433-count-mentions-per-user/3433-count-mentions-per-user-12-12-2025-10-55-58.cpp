class Solution {
public:
    vector<int> countMentions(int n, vector<vector<string>>& events) {
        sort(events.begin(), events.end(), [&](const vector<string>& lth, const vector<string>& rth) {
            int lth_timestamp = stoi(lth[1]);
            int rth_timestamp = stoi(rth[1]);
            if (lth_timestamp != rth_timestamp) {
                return lth_timestamp < rth_timestamp;
            }
            if (rth[0] == "OFFLINE") {
                return false;
            }
            return true;
        });

        vector<int> mentions(n,0);
        set<int> online;
        vector<int> onlineAt(n,0);
        for(auto e:events){
            int timeStamp = stoi(e[1]);
            if(e[0]=="OFFLINE"){
                int id = stoi(e[2]);
                online.erase(id);
                onlineAt[id] = timeStamp+60;
            }
            else{
                for(int i=0; i<n; i++){
                    if(timeStamp>=onlineAt[i]){
                        online.insert(i);
                        onlineAt[i]=0;
                    }
                }
                if(e[2]=="ALL"){
                    for(int i=0; i<n; i++) mentions[i]++;
                }
                else if(e[2]=="HERE"){
                    for(auto i:online) mentions[i]++;
                }
                else{
                    int id = 0;
                    for (int i=0; i <e[2].size(); i++) {
                        if (isdigit(e[2][i])) {
                            id = id*10 + (e[2][i] - '0');
                        }
                        if (i+1==e[2].size() || e[2][i+1] == ' ') {
                            mentions[id]++;
                            id = 0;
                        }
                    }
                }
            }
        }
        return mentions;
    }
};