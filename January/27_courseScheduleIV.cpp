class Solution {
public:
    bool dfs(unordered_map<int, vector<int>>& adj, int u, int v, vector<bool>& visited){
        visited[u] = true;
        if(u == v) return true;

        bool isReachable = false;
        for(auto& adjNode: adj[u]){
            if(!visited[adjNode])
                isReachable = isReachable || dfs(adj, adjNode, v, visited);
        }

        return isReachable;
    }

    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> adj;

        for(auto& edge : prerequisites){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
        }

        int Q = queries.size();
        vector<bool> result(Q);

        for(int i = 0; i < Q; i++){
            int u = queries[i][0];
            int v = queries[i][1];

            vector<bool> visited(numCourses, false);
            result[i] = dfs(adj, u, v, visited);
        }

        return result;
    }
};