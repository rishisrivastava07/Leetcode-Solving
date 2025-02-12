//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution {
    void bfs(int u, vector<int> adjL[], vector<bool> &vis){
        queue<int> q;
        
        q.push(u);
        vis[u] = 1;
        
        while(!q.empty()){
            int currNode = q.front();
            q.pop();
            
            for(auto adjecentNodes : adjL[currNode]){
                if(!vis[adjecentNodes]){
                    q.push(adjecentNodes);
                    vis[adjecentNodes] = 1;
                }
            }
        }
    }
    void dfs(int u, vector<int> adjL[], vector<bool> &vis){
        vis[u] = 1;
        
        for(auto adjNodes : adjL[u]){
            if(!vis[adjNodes]){
                vis[adjNodes] = 1;
                dfs(adjNodes, adjL, vis);
            }
        }
    }
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<int> adjL[V];
        for(int i = 0; i < V; i++){
            for(int j = i; j < V; j++){
                if(i != j && adj[i][j] == 1){
                    adjL[i].push_back(j);
                    adjL[j].push_back(i);
                }
            }
        }
        
        vector<bool> vis(V, 0);
        int count = 0;

        // using DFS
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                dfs(i, adjL, vis);
                count++;
            }
        }

        // using BFS
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                bfs(i, adjL, vis);
                count++;
            }
        }
        
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends