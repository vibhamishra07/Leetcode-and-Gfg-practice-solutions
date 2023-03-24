class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>>adj(n+1);
        for(auto &edges: connections){
            adj[edges[0]].push_back({edges[1], 1});
            adj[edges[1]].push_back({edges[0], -1});
        }
        
        vector<int>visited(n+1, 0);
        int count=0;
        dfs(adj, visited, count, 0);
        return count;
    }
    
    void dfs(vector<vector<pair<int, int>>>&adj, vector<int>&visited, int &count, int node){
        visited[node]=1;
        for(auto &[curr, dis]: adj[node]){
            if(!visited[curr]){
                if(dis==1) count++;
                dfs(adj, visited, count, curr);
            }
        }
    }
};