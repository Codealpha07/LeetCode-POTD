class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        // Sort by start time 
        sort(meetings.begin(), meetings.end());
        
        // Make PQ for free rooms(roomID) and one for busy rooms(FreeTime, roomID)
        priority_queue<int, vector<int>, greater<int>> freeRooms;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> busy;

        for(int i=0; i<n; i++) freeRooms.push(i); // Initially all free

        //  Map for counting the frequency
        unordered_map<int, int> count;

        freeRooms.pop();
        busy.push({meetings[0][1], 0});
        count[0]++;

        int ans=0, cnt=1;

        for(int i=1; i<meetings.size(); i++){
            int s=meetings[i][0], e=meetings[i][1];

            while(!busy.empty() && s>=busy.top().first){
                freeRooms.push(busy.top().second);
                busy.pop();
            }

            if(freeRooms.empty()){
                e += busy.top().first-s;
                s = busy.top().first;
                freeRooms.push(busy.top().second);
                busy.pop();
            }

            int id = freeRooms.top(); freeRooms.pop();
            busy.push({e, id});
            count[id]++;
            if(count[id]>=cnt){
                (count[id]==cnt) ? ans=min(ans, id) : ans=id;
                cnt=count[id];
            }
        }

        return ans;
    }
};