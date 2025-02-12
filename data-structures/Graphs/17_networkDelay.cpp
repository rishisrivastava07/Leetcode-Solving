class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Step - 1 : builting a weighted directed graph
        unordered_map<int, vector<pair<int, int>>> adj;
        for(auto& vec : times){
            int u = vec[0];
            int v = vec[1];
            int t = vec[2];
            adj[u].push_back({v, t});
        }

        // Step - 2 : Apply Dijkstra's Algorithm
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> time(n+1, INT_MAX);

        time[k] = 0;
        pq.push({0, k});

        while(!pq.empty()){
            int wt = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            for(auto& vec : adj[u]){
                int v = vec.first;
                int w = vec.second;

                if(wt + w < time[v]){
                    time[v] = wt + w;
                    pq.push({wt + w, v});
                }
            }
        }

        // Step - 3 : Calculate the maximum time from the time array
        int minTime = INT_MIN;
        for(int i  = 1; i <= n; i++){
            minTime = max(minTime, time[i]);
        }

        return minTime == INT_MAX ? -1 : minTime;
    }
};