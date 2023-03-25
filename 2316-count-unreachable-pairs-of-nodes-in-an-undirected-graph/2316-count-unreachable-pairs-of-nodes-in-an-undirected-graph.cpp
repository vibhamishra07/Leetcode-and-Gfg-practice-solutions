class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>>adj(n);
        
        for(auto &edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<int>visited(n, 0);
        long long result=0, num=0;
        for(int i=0; i<n; i++){
            if(visited[i]!=1){
                long long count=0;
                dfs(adj, visited, i, count);
                result+=count*(n-count-num);
                num+=count;
            }
        }
        return result;
    }
    void dfs(vector<vector<int>>&adj, vector<int>&visited, int node, long long &count){
        visited[node]=1;
        count++;
        for(auto &curr:adj[node]){
            if(visited[curr]!=1){
                dfs(adj, visited, curr, count);
            }
        }
    }
};