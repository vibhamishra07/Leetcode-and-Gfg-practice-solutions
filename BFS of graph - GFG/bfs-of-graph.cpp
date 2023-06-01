//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        queue<int>que;
        que.push(0);
        vector<bool>visited(V, false);
        vector<int>ans;
        ans.push_back(0);
        visited[0]=true;
        while(!que.empty()){
            
            int p=que.front();
            que.pop();
        
            for(auto &c:adj[p]){
                if(!visited[c]){
                   que.push(c);
                   visited[c]=true;
                   ans.push_back(c);
                }
            }
        }
        return ans;
    }
    
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends