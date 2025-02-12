class Solution {
    bool kahnsAlgo(int numCourses,unordered_map<int, vector<int>> & adj, vector<int> &inDegree){
        int count = 0;
        queue<int> q;
	    for(int i = 0; i < inDegree.size(); i++){
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
	    
	    if(count == numCourses) return true;
	    return false;
    }

    bool dfsCycle(int u, unordered_map<int, vector<int>> &adj, vector<bool>& vis, vector<bool>& inRecursion){
        vis[u] = true;
        inRecursion[u] = true;
        
        for(auto& v: adj[u]){
            if(vis[v] == false && dfsCycle(v, adj, vis, inRecursion)) return true;
            else if(inRecursion[v] == true) return true;
        }
        
        inRecursion[u] = false;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector<int> inDegree(numCourses, 0);    // Kahn's Algorithm

        // built a graph using adjecency list
        for(auto& vec : prerequisites){
            int a = vec[0];
            int b = vec[1];

            // b ---> a
            adj[b].push_back(a);
            inDegree[a]++;
        }

        // Using BFS
        return kahnsAlgo(numCourses, adj, inDegree);
        
        // Using DFS
        vector<bool> vis(numCourses, 0);
        vector<bool> inRecursion(numCourses, 0);

        
        for(int i = 0; i < numCourses; i++){
            // if cycle found then we can't solve this DAG so return false 
            // else return true;
            if(!vis[i] && dfsCycle(i, adj, vis, inRecursion)) return false;
        }

        return true;
    }
};