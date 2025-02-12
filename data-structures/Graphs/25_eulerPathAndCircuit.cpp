//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    void DFS(int u, vector<int> adj[], vector<bool>& visited){
        visited[u] = true;
        
        for(auto& v : adj[u]){
            if(!visited[v]) DFS(v, adj, visited);
        }
    }
    
    bool isConnected(int V, vector<int> adj[]){
        int nonZeroVertex = -1;
        
        // find the nonZeroVertex
        for(int i = 0; i < V; i++){
            if(adj[i].size() > 0){
                nonZeroVertex = i;
                break;
            }
        }
        
        // apply DFS on nonZeroVertex
        vector<bool> visited(V, false);
        DFS(nonZeroVertex, adj, visited);
        
        // check for all nonZeroVertices are marked visited
        for(int i = 0; i < V; i++){
            if(visited[i] == false && adj[i].size() > 0) return false;
        }
        return true;
    }
public:
	int isEulerCircuit(int V, vector<int>adj[]){
        // checking for the connected components
        if(isConnected(V, adj) == false) return false;
        
        // storing the degree count
        vector<int> inDegree(V);
        for(int u = 0; u < V; u++){
            int deg = adj[u].size();
            inDegree[u] = deg;
        }
        
        
        int oddDegree = 0;
        for(auto& deg : inDegree){
            if(deg%2 != 0) oddDegree++;
        }
        
        // if odd degree == 0 ---> Eulers Circuit
        if(oddDegree == 0) return 2;
        // if odd degree == 2 ---> Eulers Path
        else if(oddDegree == 2) return 1;
        // else not any of the above
        return 0;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		int ans = obj.isEulerCircuit(V, adj);
		cout << ans <<"\n";	}
	return 0;
}
// } Driver Code Ends