class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<vector<int>> Robots(n, vector<int>(4));
        for(int i=0; i<n; i++){
            Robots[i] = {positions[i], healths[i], directions[i], i};
        }
        sort(Robots.begin(), Robots.end()); // Sorting on the basis of position
        stack <vector<int>> s;
        int i=0;
        while(i<n){
            if(s.empty() && i<n){s.push(Robots[i]); i++;}
            while(!s.empty() && i<n){
                // Won't collide 
                if((s.top()[2]==Robots[i][2]) || (s.top()[2]=='L' && 
                    Robots[i][2]=='R')){
                    s.push(Robots[i]); i++;
                }
                // Collision
                else{
                    if(Robots[i][1] > s.top()[1]){
                        s.pop();
                        Robots[i][1]--;
                    }
                    else if(Robots[i][1] < s.top()[1]){
                        s.top()[1]--;
                        i++;
                    }
                    else{s.pop(); i++;}
                }
            }
        }
        vector<pair<int, int>>left;
        while(!s.empty()){
            left.push_back(make_pair(s.top()[3], s.top()[1]));
            s.pop();
        }
        sort(left.begin(), left.end());
        vector<int> ans;
        for(auto &pair : left){
            ans.push_back(pair.second);
        }
        return ans;
    }
};