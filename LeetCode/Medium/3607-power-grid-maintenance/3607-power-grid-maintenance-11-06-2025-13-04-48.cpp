class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        vector<vector<int>> adj(c+1);
        for(auto e:connections){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> compID(c+1,-1); // For assigning component ID to each station 
        vector<set<int>> compSet; // Vector of set of online stations for that particular component
        vector<bool> vis(c+1,false);
        int currCompID = 0;
        for(int i=1; i<=c; i++){
            if(!vis[i]){
                compSet.push_back({});
                dfs(i, adj, compID, compSet, vis, currCompID);
                currCompID++;
            }
        }   
        vector<int> ans;
        for(auto q:queries){
            int i = q[1];
            if(q[0]==2){
                if(compSet[compID[i]].find(i)!=compSet[compID[i]].end()){
                    compSet[compID[i]].erase(i);
                }
            }
            else{
                if(compSet[compID[i]].empty()) ans.push_back(-1);
                else if(compSet[compID[i]].find(i)!=compSet[compID[i]].end()){
                    ans.push_back(i);
                }
                else{
                    ans.push_back(*compSet[compID[i]].begin());
                }
            }
        }
        return ans;
    }
private:
    void dfs(int i, vector<vector<int>> &adj, vector<int>& compID, vector<set<int>>& compSet, vector<bool>& vis, int currCompID){
        vis[i]=true;
        compID[i]=currCompID;
        compSet[currCompID].insert(i);
        for(auto neighbour:adj[i]){
            if(!vis[neighbour]) dfs(neighbour, adj, compID, compSet, vis, currCompID);
        }
    }
};