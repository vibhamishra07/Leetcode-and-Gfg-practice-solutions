class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        
        
        vector<vector<pair<int, int>>> adj(n+1);
        
        for( auto elem : roads){
            int u=elem[0];
            int v=elem[1];
            int dist=elem[2];
            
            adj[u].push_back(make_pair(v, dist));
            adj[v].push_back(make_pair(u, dist));
        }
        
        
        vector<int>visited(n+1, 0);
        int result=INT_MAX;
        
        dfs(adj, visited, result, 1);
        return result;
    }
    
    int dfs(vector<vector<pair<int, int>>> &adj,  vector<int>&visited, int &result, int parent){
            visited[parent]=1;
            for(auto& [v, dist] : adj[parent]){
                result=min(dist, result);
                if(visited[v]==0){
                    visited[v]=1;
                    result=min(result, dfs(adj, visited, result, v));
                    
                }
            }
        return result;
        
    }
};