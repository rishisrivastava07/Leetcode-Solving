//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    bool dfsCycle(int u, vector<int> adj[], vector<bool>& vis, vector<bool>& inRecursion){
        vis[u] = true;
        inRecursion[u] = true;
        
        for(auto& v: adj[u]){
            if(vis[v] == false && dfsCycle(v, adj, vis, inRecursion)) return true;
            else if(inRecursion[v] == true) return true;
        }
        
        inRecursion[u] = false;
        return false;
    }
    bool bfsCycle(int V, vector<int> adj[]){
        int count = 0;
	    vector<int> inDegree(V, 0);
	    
	    for(int i = 0; i < V; i++){
	        for(auto it : adj[i]){
	            inDegree[it]++;
	        }
	    }
	    
	    queue<int> q;
	    for(int i = 0; i < V; i++){
	        if(inDegree[i] == 0){
	            q.push(i);
	            count++;
	        }
	    }
	    
	    while(!q.empty()){
	        int currNode = q.front();
	        q.pop();
	        
	        for(auto adjNodes : adj[currNode]){
	            inDegree[adjNodes]--;
	            if(inDegree[adjNodes] == 0){
	                q.push(adjNodes);
	                count++;
	            }
	        }
	    }
	    
	    if(count == V) return false;
	    return true;
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<bool> vis(V, 0);
        vector<bool> inRecursion(V, 0);

        // using DFS
        for(int i = 0; i < V; i++){
            if(!vis[i] && dfsCycle(i, adj, vis, inRecursion)) return true;
        }

        // using BFS
        if(bfsCycle(V, adj)) return true;
        
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends