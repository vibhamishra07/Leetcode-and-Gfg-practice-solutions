class Solution {
public:
    int ans=-1;
    int longestCycle(vector<int>& edges) {
        int n=edges.size();
        vector<int>visited(n, 0);
        vector<int>count(n, 1);
        vector<int>inRecursion(n, 0);

        for(int i=0; i<n; i++){
            
            if(!visited[i]){
                dfs(i, edges, visited, count, inRecursion);
            }
            
        }
        return ans;
    }
    void dfs(int node, vector<int>& edges, vector<int>&visited, vector<int>&count, vector<int>&inRecursion){
        
        if(node!=-1){
            visited[node]=1;
            inRecursion[node]=1;
            int curr=edges[node];
            if(curr!=-1 && !visited[curr]){   
               count[curr]=count[node]+1;
                dfs(curr, edges, visited, count, inRecursion);
            }else if(curr!=-1 && inRecursion[curr]==1){
                ans=max(ans, count[node]-count[curr]+1);
            }
            inRecursion[node]=0;
            
        }
        
    }
};