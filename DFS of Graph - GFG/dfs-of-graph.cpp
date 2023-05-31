//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int>ans;
        vector<bool>visited(V, 0);
        dfs(adj, 0, ans,visited);
        return ans;
    }
    
    void dfs(vector<int> adj[], int p,vector<int>&ans, vector<bool>&visited){
        if(visited[p]==true){
            return ;
        }
        ans.push_back(p);
        visited[p]=true;
        for(auto &c:adj[p]){
            if(visited[c]!=true){
                dfs(adj, c, ans, visited);
            }
        }
        
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
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends