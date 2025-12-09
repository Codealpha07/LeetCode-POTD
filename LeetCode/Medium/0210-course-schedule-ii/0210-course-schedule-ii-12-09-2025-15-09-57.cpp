class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        vector<int> inDegree(numCourses);
        vector<vector<int>> adj(numCourses);
        for(auto e:prerequisites){
            adj[e[1]].push_back(e[0]);
            inDegree[e[0]]++;
        }
        queue<int> q;
        for(int i=0; i<numCourses; i++){
            if(inDegree[i]==0) q.push(i); 
        }
        int count = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            count++;
            for (auto &nbr : adj[node]) {
                inDegree[nbr]--;
                if (inDegree[nbr] == 0)
                    q.push(nbr);
            }
        }
        if(count!=numCourses) return {};
        return ans;
    }
};