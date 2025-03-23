class Solution {
    public:
        void dfs(int node, unordered_map<int, vector<int>>& adj, vector<bool>& vis, int& v, int& e){
            vis[node] = true;
            v++;
            e += adj[node].size();
        
            for(int &ngbr : adj[node]){
                if(!vis[ngbr]) dfs(ngbr, adj, vis, v, e);
            }
        }
        int countCompleteComponents(int n, vector<vector<int>>& edges) {
            // Creating the adjeceny list for the graph
            unordered_map<int, vector<int>> adj;
            for(auto& edge : edges){
                int u = edge[0];
                int v = edge[1];
    
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
    
            int component = 0;
            // now using dfs we will count the edges and vertices
            vector<bool> vis(n, false);
    
            for(int i = 0; i < n; i++){
                if(!vis[i]){
                    int v = 0, e = 0;
                    dfs(i, adj, vis, v, e);
                    if(v*(v-1)/2 == e/2) component++;
                }
            }
    
            return component;
        }
    };