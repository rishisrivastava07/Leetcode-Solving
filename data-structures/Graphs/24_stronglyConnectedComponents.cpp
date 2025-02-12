//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    void dfsFill(int node, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& st){
        visited[node] = true;
        
        for(auto& adjNodes : adj[node]){
            if(!visited[adjNodes]){
                dfsFill(adjNodes, adj, visited, st);
            }
        }
        st.push(node);
    }
    
    void dfs(int u, vector<vector<int>>& adj, vector<bool>& visited){
        visited[u] = true;
        
        for(auto& v : adj[u]){
            if(!visited[v]){
                dfs(v, adj, visited);
            }
        }
    }
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        // Step - 1 : Topological Order stored in stack
        stack<int> st;
        vector<bool> visited(V, false);
        
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                dfsFill(i, adj, visited, st);
            }
        }
        
        // Step - 2 : Reverse the graph
        vector<vector<int>> reversedGraph(V);
        
        for(int i = 0; i < V; i++){
            for(int& v : adj[i]){
                reversedGraph[v].push_back(i);
            }
        }
        
        // Step - 3 : Traversing in stack order by DFS
        int scc = 0;
        visited = vector<bool>(V, false);
        
        while(!st.empty()){
            int node = st.top();
            st.pop();
            
            if(!visited[node]){
                dfs(node, reversedGraph, visited);
                scc++;
            }
        }
        
        return scc;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends