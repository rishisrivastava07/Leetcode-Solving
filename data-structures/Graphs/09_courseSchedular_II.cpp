class Solution {
    void kahnsAlgo(int numCourses,unordered_map<int, vector<int>> & adj, vector<int> &inDegree){
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
    }

	bool hasCycle;

    void detectCycleAndTopoSort(int u, unordered_map<int, vector<int>>& adjList, vector<bool> &vis, stack<int>& st, vector<bool> &inRecursion){
        vis[u] = true;
        inRecursion[u] = true;

        for(auto &adjecentNodes : adjList[u]){
            if(!vis[adjecentNodes]){
                detectCycleAndTopoSort(adjecentNodes, adjList, vis, st, inRecursion);
            }
            else if(inRecursion[adjecentNodes]){
                hasCycle = true;
                return;
            }
        }

        st.push(u);
        inRecursion[u] = false;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
		// Kahn's Algorithm
        unordered_map<int, vector<int>> adj;
        vector<int> inDegree(numCourses, 0);    
        vector<int> ans;

        // built a graph using adjecency list
        for(auto& vec : prerequisites){
            int a = vec[0];
            int b = vec[1];

            // b ---> a
            adj[b].push_back(a);
            inDegree[a]++;
        }

        queue<int> q;
	    for(int i = 0; i < inDegree.size(); i++){
	        if(inDegree[i] == 0) q.push(i);
	    }
	    
	    while(!q.empty()){
	        int currNode = q.front();
	        q.pop();
	        
	        ans.push_back(currNode);
	        
	        for(auto adjNodes : adj[currNode]){
	            inDegree[adjNodes]--;
	            if(inDegree[adjNodes] == 0){
	                q.push(adjNodes);
	            }
	        }
	    }
	    
	    if(ans.size() == numCourses) return ans;

        ans.clear();
        return ans;


		// Using DFS
		int V = numCourses;
        unordered_map<int, vector<int>> adjList;
        hasCycle = false;

        for(auto& vec : prerequisites){
            int a = vec[0];
            int b = vec[1];

            // b ---> a
            adjList[b].push_back(a);
        }       


        vector<bool> vis(V, 0), inRecursion(V, 0);
        stack<int> st;

        for(int i = 0; i < V; i++){
	        if(!vis[i]){
	            detectCycleAndTopoSort(i, adjList, vis, st, inRecursion);
	        }
	    }

        vector<int> ans;
        
        if(hasCycle == true) return {};

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};