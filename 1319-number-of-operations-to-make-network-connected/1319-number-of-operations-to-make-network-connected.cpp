class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        if(connections.size() < n-1) return -1;
        vector<vector<int>>adj(n);
        
        for(auto edges:connections){
            int u=edges[0];
            int v=edges[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
            
        }
        
        vector<int>visited(n, 0);
        int ans=0;
        for(int i=0; i<n; i++){
            if(visited[i]!=1){
                dfs(adj, visited, i);
                ans++;
            }
        }
        return  ans-1;
        
    }
    
    void dfs(vector<vector<int>>&adj, vector<int>&visited, int parent){
        visited[parent]=1;
        for(auto &curr:adj[parent]){
           if(!visited[curr])
                dfs(adj, visited, curr);
        }
    }
};