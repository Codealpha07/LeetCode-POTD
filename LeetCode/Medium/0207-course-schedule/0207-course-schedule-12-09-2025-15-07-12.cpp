class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
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
            count++;
            for (auto &nbr : adj[node]) {
                inDegree[nbr]--;
                if (inDegree[nbr] == 0)
                    q.push(nbr);
            }
        }
        return count==numCourses;
    }
};