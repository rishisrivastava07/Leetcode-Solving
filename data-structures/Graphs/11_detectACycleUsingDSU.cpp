//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    int find(int i, vector<int>& parent){
        if(i == parent[i]) return i;
        
        return parent[i] = find(parent[i], parent);
    }
    
    void Union(int a, int b, vector<int>& parent, vector<int>& rank){
        int a_parent = find(a, parent);
        int b_parent = find(b, parent);
        
        if(a_parent == b_parent) return;
        if(rank[a_parent] > rank[b_parent]) parent[b_parent] = a_parent;
        else if(rank[a_parent] < rank[b_parent]) parent[a_parent] = b_parent;
        else {
            parent[b_parent] = a_parent;
            rank[a_parent]++;
        }
    }
    public:
    //Function to detect cycle using DSU in an undirected graph.
	int detectCycle(int V, vector<int>adj[])
	{
	    // Code here
	    vector<int> rank(V, 1);
	    vector<int> parent(V);
	    
	    for(int i = 0; i < V; i++) parent[i] = i;
	    
	    for(int u = 0; u < V; u++){
	        for(auto& v : adj[u]){
	            if(u < v){
    	            int u_parent = find(u, parent);
    	            int v_parent = find(v, parent);
    	            
    	            if(u_parent == v_parent) return true;
    	            Union(u, v, parent, rank);
	            }
	        }
	    }
	    
	    return false;
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
		int ans = obj.detectCycle(V, adj);
		cout << ans <<"\n";	}
	return 0;
}
// } Driver Code Ends