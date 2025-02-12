//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.

    // Using Kruskals Algorithm
    int find(int i, vector<int>& parent){
        if(i == parent[i]) return i;
        
        return parent[i] = find(parent[i], parent);
    }
    
    void Union(int u, int v, vector<int>& parent, vector<int> &rank){
        int parent_u = find(u, parent);
        int parent_v = find(v, parent);
        
        if(parent_u == parent_v) return;
        else if(rank[parent_u] < rank[parent_v]){
            parent[parent_u] = parent_v;
        } else if(rank[parent_u] > rank[parent_v]){
            parent[parent_v] = parent_u;
        } else{
            parent[parent_u] = parent_v;
            rank[parent_v]++;
        }
    }
    
    int kruskalsAlgorithm(vector<vector<int>>& vec, vector<int>& parent, vector<int>& rank){
        int sum = 0;
        
        for(auto& it : vec){
            int p1 = find(it[0], parent);
            int p2 = find(it[1], parent);
            
            if(p1 != p2){
                Union(p1, p2, parent, rank);
                sum += it[2];
            }
        }
        
        return sum;
    }

    // Using Prims Algorithm
	typedef pair<int, pair<int, int>> P;
    int primsAlgorithm(int V, vector<vector<int>> adj[]){
        // Step - 1 : Make an inMST & parent Vector. Also make a min heap
        vector<bool> inMST(V, false);
        vector<int> parentV(V, -1);
        
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, {0, -1}});
        
        int sum = 0;
        
        while(!pq.empty()){
            int wt = pq.top().first;
            int node = pq.top().second.first;
            int parent = pq.top().second.second;
            pq.pop();
            
            if(inMST[node] == true) continue;
            
            inMST[node] = true;
            parentV[node] = parent;
            sum += wt;
            
            for(auto& vec : adj[node]){
                int adjNode = vec[0];
                int adjNode_wt = vec[1];
                
                if(!inMST[adjNode] && parentV[adjNode] == -1){
                    pq.push({adjNode_wt, {adjNode, node}});
                }
            }
        }
        
        return sum;
    }


    int spanningTree(int V, vector<vector<int>> adj[]){
        vector<vector<int>> vec;
        
        for(int u = 0; u < V; u++){
            for(auto& temp : adj[u]){
                int v = temp[0];
                int wt = temp[1];
                
                vec.push_back({u, v, wt});
            }
        }
        
        auto comparator = [&](vector<int>& vec1, vector<int>& vec2){
            return vec1[2] < vec2[2];
        };
        
        sort(begin(vec), end(vec), comparator);
     
        vector<int> parent(V);
        vector<int> rank(V, 1);
        
        for(int i = 0; i < V; i++){
            parent[i] = i;
        }
        
        return kruskalsAlgorithm(vec, parent, rank);   
        return primsAlgorithm(V, adj);
    }

};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends