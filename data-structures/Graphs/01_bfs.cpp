//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // it is used to calculate the shortest path using BFS
        vector<int> ans;
        vector<bool> vis(V, 0);
        queue<int> q;
        
        q.push(0);
        vis[0] = 1;
        
        while(!q.empty()){
            int currNode = q.front();
            q.pop();
            
            ans.push_back(currNode);
            
            for(auto adjecentNodes : adj[currNode]){
                if(!vis[adjecentNodes]){
                    q.push(adjecentNodes);
                    vis[adjecentNodes] = 1;
                }
            }
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends