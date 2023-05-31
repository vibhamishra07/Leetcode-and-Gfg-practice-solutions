//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        
        vector<bool>visited(V+1, false);
        for(int i=0; i<V; i++){
            if(!visited[i] && bfs(adj, i, visited)){
              return true;
            }
            
        }
        return false;
        
    }
    bool bfs(vector<int>adj[],int i, vector<bool>&visited){
        queue<pair<int, int>>que;
        que.push({i, -1});
        visited[i]=true;
        while(!que.empty()){
            int p=que.front().first;
            int parent=que.front().second;
            que.pop();
            for(auto &c:adj[p]){
                if(c==parent) continue;
                if(visited[c]) return true;
                visited[c]=true;
                que.push({c, p});
            }
        }
        return false;
    }
    
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends