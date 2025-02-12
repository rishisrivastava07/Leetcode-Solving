//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    bool dfsCycle(int u, vector<int> adj[], vector<bool>& vis, int parent){
        vis[u] = true;
                
        for(auto& v: adj[u]){
            if(!vis[v]){
                vis[v] = 1;
                if(dfsCycle(v, adj, vis, u)) return true;
            }
            else if(vis[v] && v != parent) return true;
        }
        return false;
    }
    bool bfsCycle(int u, int parentNode, vector<int> adj[], vector<bool>& vis){
        queue<pair<int, int>> q;
        q.push({u, parentNode});
        vis[u] = 1;
        
        while(!q.empty()){
            int currNode = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for(auto v : adj[currNode]){
                if(vis[v] && v == parent) continue;
                if(vis[v] && v != parent) return true;
                if(!vis[v]){
                    q.push({v, currNode});
                    vis[v] = 1;
                }
            }
        }
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool> vis(V, 0);
        
        for(int i = 0; i < V; i++){
            if(!vis[i] && dfsCycle(i, adj, vis, -1)) return true;
        }

        for(int i = 0; i < V; i++){
            if(!vis[i] && bfsCycle(i, -1, adj, vis)) return true;
        }

        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends